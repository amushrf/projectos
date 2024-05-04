#ifndef _QUANTUM_END_EVENT_H_
#define _QUANTUM_END_EVENT_H_

#include "Event.h"
#include "Job.h"

class SystemState;

/**
 * @class QuantumEndEvent
 * @brief Represents an event that signifies the end of a quantum in a scheduling simulator.
 * 
 * This class is derived from the base class Event and provides functionality to process the quantum end event.
 */
class QuantumEndEvent : public Event {
public: 
    /**
     * @brief Constructs a QuantumEndEvent object with the given time.
     * @param time The time at which the quantum ends.
     */
    QuantumEndEvent(int time);
    
    /**
     * @brief Processes the quantum end event.
     * @param state The current system state.
     */
    void process(SystemState& state);
    
    /**
     * @brief Gets the type of the event.
     * @return The type of the event.
     */
    Type get_type() const;
};

#endif // _QUANTUM_END_EVENT_H_
