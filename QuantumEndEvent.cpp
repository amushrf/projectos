#include <iostream>
#include <stdexcept>
#include <vector>

#include "QuantumEndEvent.h"
#include "SystemState.h"

using namespace std;

QuantumEndEvent::QuantumEndEvent(int time) : Event(time) {
}
    
/**
 * @brief Processes the QuantumEndEvent.
 * 
 * This function is responsible for processing the QuantumEndEvent. It prints the current time
 * and a message indicating that the quantum has ended. The QuantumEndEvent itself doesn't perform
 * any specific actions other than triggering the event processing mechanism in the main() function
 * to step the CPU and swap jobs.
 * 
 * @param state The reference to the SystemState object.
 */
void QuantumEndEvent::process(SystemState& state) {
    cout << get_time() << ": Quantum ended" << endl;
    // QuantumEndEvent itself doesn't do anything except trigger the event 
    // processing mechanism in main() to step the CPU and swap jobs
}

Event::Type QuantumEndEvent::get_type() const {
    return Event::Type::Internal;
}
