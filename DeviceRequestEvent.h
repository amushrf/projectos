#ifndef _DEVICE_REQUEST_EVENT_H_
#define _DEVICE_REQUEST_EVENT_H_

#include "Event.h"
#include "Job.h"

class SystemState;

/**
 * @class DeviceRequestEvent
 * @brief Represents an event where a job requests devices in the system.
 * 
 * This class inherits from the base class Event and provides specific functionality
 * for handling device request events.
 */
class DeviceRequestEvent : public Event {
public: 
    /**
     * @brief Constructs a DeviceRequestEvent object with the given parameters.
     * @param time The time at which the event occurs.
     * @param job_number The number of the job making the device request.
     * @param requested_devices The number of devices requested by the job.
     */
    DeviceRequestEvent(int time, int job_number, int requested_devices);
    
    /**
     * @brief Processes the device request event and updates the system state accordingly.
     * @param state The current system state.
     */
    void process(SystemState& state);
    
    /**
     * @brief Gets the type of the event.
     * @return The type of the event.
     */
    Type get_type() const;
    
private:
    int m_job_number; ///< The number of the job making the device request.
    int m_requested_devices; ///< The number of devices requested by the job.
};

#endif // _DEVICE_REQUEST_EVENT_H_
