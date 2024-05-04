#ifndef _EVENT_H_
#define _EVENT_H_

class SystemState;

/**
 * @class Event
 * @brief Represents an event in the scheduling simulator.
 * 
 * The Event class is an abstract base class that represents an event in the scheduling simulator.
 * It provides common functionality for all types of events, such as internal and external events.
 */
class Event {
public: 
    /**
     * @enum Type
     * @brief Represents the type of an event.
     * 
     * The Type enum class represents the type of an event, which can be either internal or external.
     */
    enum class Type {
        Internal, 
        External,
    };
    
    /**
     * @brief Constructs an Event object with the specified time.
     * 
     * @param time The time at which the event occurs.
     */
    explicit Event(int time);
    
    /**
     * @brief Destroys the Event object.
     */
    virtual ~Event();
    
    /**
     * @brief Processes the event and updates the system state.
     * 
     * This pure virtual function must be implemented by derived classes to process the event
     * and update the system state accordingly.
     * 
     * @param state The current system state.
     */
    virtual void process(SystemState& state) = 0;
    
    /**
     * @brief Gets the time at which the event occurs.
     * 
     * @return The time at which the event occurs.
     */
    int get_time() const;
    
    /**
     * @brief Gets the type of the event.
     * 
     * This pure virtual function must be implemented by derived classes to return the type of the event.
     * 
     * @return The type of the event.
     */
    virtual Type get_type() const = 0;
    
    /**
     * @brief Compares two events based on their time.
     * 
     * This operator compares two events based on their time. It returns true if the time of the current event
     * is less than the time of the other event, and false otherwise.
     * 
     * @param other The other event to compare with.
     * @return True if the time of the current event is less than the time of the other event, false otherwise.
     */
    bool operator< (const Event& other) const;

private:
    int m_time; /**< The time at which the event occurs. */
};

#endif // _EVENT_H_
