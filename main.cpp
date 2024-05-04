#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <unordered_map>

#include "SystemState.h"
#include "Event.h"
#include "JobArrivalEvent.h"
#include "DeviceRequestEvent.h"
#include "DeviceReleaseEvent.h"
#include "DisplayEvent.h"
#include "Job.h"

#define CONFIGURATION "C"
#define MAX_MEMORY "M"
#define TIME_EXCESS "L"
#define MAX_DEVICES "S"
#define QUANTUM_LENGTH "Q"
#define JOB_ARRIVAL "A"
#define JOB_NUMBER "J"
#define RUNTIME "R"
#define PRIORITY "P"
#define DEVICE_REQUEST "Q"
#define NUM_DEVICES "D"
#define DEVICE_RELEASE "L"
#define DISPLAY "D"

using namespace std;

/**
 * @brief Parses the command tokens and returns a map of parameter-value pairs.
 * 
 * @param tokens The command tokens to parse.
 * @return unordered_map<string, int> A map of parameter-value pairs.
 * @throws runtime_error if the input line is malformed.
 */
unordered_map<string, int> parse_command_tokens(const vector<string>& tokens) {
    unordered_map<string, int> pairs;
    for (unsigned int i = 2; i < tokens.size(); i++) {
        if (tokens[i].size() < 3) {
            throw runtime_error("Error: Malformed input line");
        }
        string parameter = tokens[i].substr(0, 1);
        string value = tokens[i].substr(2);
        pairs.insert({{parameter, atoi(value.c_str())}});
    }
    return pairs;
}

/**
 * @brief Splits a string into tokens based on a delimiter.
 * 
 * @param str The string to split.
 * @param delimiter The delimiter character.
 * @return vector<string> A vector of tokens.
 */
vector<string> split(const string& str, char delimiter) {
   vector<string> tokens;
   string token;
   istringstream tokenStream(str);
   while (getline(tokenStream, token, delimiter)) {
      tokens.push_back(token);
   }
   return tokens;
}

/**
 * @brief Processes events up to a given time in the system state.
 * 
 * @param time The time up to which events should be processed.
 * @param state The system state.
 */
void process_events_through_time(int time, SystemState& state) {
    while (state.has_next_event() && state.get_next_event()->get_time() <= time) {
        // Step cpu to current time (which will reduce remaining time for 
        // current process if necessary)
        int event_time = state.get_next_event()->get_time();
        state.set_time(event_time);
        
        // Process event
        Event* e = state.pop_next_event();
        e->process(state);
        delete e;
        
        // Update queues and move jobs on/off CPU if necessary
        state.update_queues();
    }
}

/**
 * The main function is the entry point of the program.
 * It reads an input file, parses the commands, and schedules events accordingly.
 * The function takes command line arguments as input, where the first argument is the input file path.
 * If no input file is specified, it throws a runtime error.
 * If the input file cannot be found, it throws a runtime error.
 * 
 * @param argc The number of command line arguments.
 * @param argv An array of command line arguments.
 * @return Returns 0 upon successful execution.
 * @throws runtime_error If the input file is not specified or cannot be found.
 */
int main(int argc, char** argv) {
    if (argc < 2) {
        throw runtime_error("Error: Please specify an input file.");
    }
    ifstream in_file(argv[1]);
    if (in_file.fail()) {
        throw runtime_error("Error: Could not find specified input file.");
    }
    
    string filename(argv[1]);
    filename.erase(filename.find_last_of("."), string::npos);
    
    SystemState* state;
    
    bool explicit_final_print = false;
    
    for (string line; getline(in_file, line);) {
        vector<string> tokens = split(line, ' ');
        if (tokens.size() < 2) {
            throw runtime_error("Error: Malformed input line");
        }
        int command_time = atoi(tokens[1].c_str());
        
        if (tokens[0] == CONFIGURATION) {
            cout << command_time << ": System configuration" << endl;
            unordered_map<string, int> pairs = parse_command_tokens(tokens);
            try {
                state = new SystemState(
                    pairs.at(MAX_MEMORY),
                    pairs.at(TIME_EXCESS), 
                    pairs.at(MAX_DEVICES), 
                    pairs.at(QUANTUM_LENGTH),
                    command_time);
            } catch (const out_of_range& e) {
                throw runtime_error("Error: Malformed input line");
            }
        } else if (tokens[0] == JOB_ARRIVAL) {
            unordered_map<string, int> pairs = parse_command_tokens(tokens);
            try {
                Job job(
                    command_time,
                    pairs.at(JOB_NUMBER),
                    pairs.at(MAX_MEMORY),
                    pairs.at(MAX_DEVICES),
                    pairs.at(RUNTIME),
                    pairs.at(PRIORITY));
                Event* e = new JobArrivalEvent(command_time, job);
                state->schedule_event(e);
            } catch (const out_of_range& e) {
                throw runtime_error("Error: Malformed input line");
            }
        } else if (tokens[0] == "Q") {
            unordered_map<string, int> pairs = parse_command_tokens(tokens);
            try {
                Event* e = new DeviceRequestEvent(command_time, 
                                                  pairs.at(JOB_NUMBER),
                                                  pairs.at(NUM_DEVICES));
                state->schedule_event(e);
            } catch (const out_of_range& e) {
                throw runtime_error("Error: Malformed input line");
            }
        } else if (tokens[0] == "L") {
            unordered_map<string, int> pairs = parse_command_tokens(tokens);
            try {
                Event* e = new DeviceReleaseEvent(command_time, 
                                                  pairs.at(JOB_NUMBER),
                                                  pairs.at(NUM_DEVICES));
                state->schedule_event(e);
            } catch (const out_of_range& e) {
                throw runtime_error("Error: Malformed input line");
            }
        } else if (tokens[0] == "D") {
            if (command_time >= END_TIME) {
                explicit_final_print = true;
            }
            Event* e = new DisplayEvent(command_time, filename);
            state->schedule_event(e);
        } else {
            cerr << command_time << ": Unknown input command" << endl;
            return 1;
        }
        
        process_events_through_time(command_time, *state);
    }
    
    if (!explicit_final_print) {
        Event* e = new DisplayEvent(END_TIME, filename);
        state->schedule_event(e);
        
        process_events_through_time(END_TIME, *state);
    }
    
    delete state;
    
    return 0;
}
