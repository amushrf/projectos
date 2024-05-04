#ifndef _DISPLAY_EVENT_H_
#define _DISPLAY_EVENT_H_

#include <string>

#include "Event.h"
#include "Job.h"

class SystemState;

/**
 * @class DisplayEvent
 * @brief A class representing a display event in a scheduling simulator.
 * 
 * The DisplayEvent class is a derived class of the Event class. It represents an event
 * that displays the current system state at a specific time.
 */
class DisplayEvent : public Event {
public: 
    /**
     * @brief Constructs a DisplayEvent object with the given time and filename.
     * @param time The time at which the display event occurs.
     * @param filename The name of the file to which the system state will be displayed.
     */
    DisplayEvent(int time, std::string filename);
    
    /**
     * @brief Processes the display event by updating the system state and displaying it.
     * @param state The current system state.
     */
    void process(SystemState& state);
    
    /**
     * @brief Returns the type of the event.
     * @return The type of the event (DISPLAY).
     */
    Type get_type() const;
    
private:
    std::string m_filename; /**< The name of the file to which the system state will be displayed. */
};

#endif // _DISPLAY_EVENT_H_
