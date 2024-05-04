#ifndef _JOB_ARRIVAL_EVENT_H_
#define _JOB_ARRIVAL_EVENT_H_

#include "Event.h"
#include "Job.h"

class SystemState;

/**
 * @class JobArrivalEvent
 * @brief Represents an event where a job arrives in the system.
 * 
 * The JobArrivalEvent class is a subclass of the Event class and is used to represent an event
 * where a job arrives in the system. It contains information about the arrival time of the job
 * and the job itself.
 */
class JobArrivalEvent : public Event {
public: 
    /**
     * @brief Constructor for JobArrivalEvent.
     * @param time The arrival time of the job.
     * @param job The job that arrives in the system.
     */
    JobArrivalEvent(int time, Job job);
    
    /**
     * @brief Process the job arrival event.
     * @param state The current system state.
     */
    void process(SystemState& state);
    
    /**
     * @brief Get the type of the event.
     * @return The type of the event.
     */
    Type get_type() const;

private:
    Job m_job; ///< The job that arrives in the system.
};

#endif // _JOB_ARRIVAL_EVENT_H_
