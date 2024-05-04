#ifndef _DEVICE_RELEASE_EVENT_H_
#define _DEVICE_RELEASE_EVENT_H_

#include "Event.h"
#include "Job.h"

class SystemState;

/**
 * @brief The DeviceReleaseEvent class represents an event where a device is released by a job.
 * 
 * This class is derived from the base class Event and provides specific functionality for device release events.
 */
class DeviceReleaseEvent : public Event {
public: 
    /**
     * @brief Constructs a DeviceReleaseEvent object with the specified time, job number, and number of released devices.
     * 
     * @param time The time at which the event occurs.
     * @param job_number The number of the job that releases the devices.
     * @param released_devices The number of devices released by the job.
     */
    DeviceReleaseEvent(int time, int job_number, int released_devices);
    
    /**
     * @brief Processes the device release event and updates the system state accordingly.
     * 
     * @param state The current system state.
     */
    void process(SystemState& state);
    
    /**
     * @brief Returns the type of the event.
     * 
     * @return The type of the event (DeviceRelease).
     */
    Type get_type() const;
    
private:
    int m_job_number; ///< The number of the job that releases the devices.
    int m_released_devices; ///< The number of devices released by the job.
};

#endif // _DEVICE_RELEASE_EVENT_H_
