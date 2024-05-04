#include <iostream>
#include <stdexcept>
#include <vector>

#include "JobArrivalEvent.h"
#include "SystemState.h"

using namespace std;

JobArrivalEvent::JobArrivalEvent(int time, Job job)
: Event(time), m_job(job) {
}
    
/**
 * Process the job arrival event.
 * This function is responsible for handling the arrival of a job in the system.
 * It checks if the job's resource requirements can be met and takes appropriate actions.
 * If the job's resource requirements cannot be met, the job is rejected.
 * If the job's memory requirement is greater than the available memory, it is placed on hold based on its priority.
 * If the job's resource requirements can be met, it is allocated memory, added to the system, and scheduled for execution.
 *
 * @param state The current system state.
 */
void JobArrivalEvent::process(SystemState& state) {
    cout << get_time() << ": Job arrival" << endl;
    if (m_job.get_max_memory() > state.get_max_memory() 
        || m_job.get_max_devices() > state.get_max_devices()) {
        cerr << "Job " << m_job.get_number() 
             << " rejected due to insufficient total system resources." 
             << endl;
        return;
    } else if (m_job.get_max_memory() > state.get_available_memory()) {
        if (m_job.get_priority() == 1) {
            state.add_job(m_job);
            state.schedule_job(SystemState::JobQueue::Hold1, m_job.get_number());
        } else if (m_job.get_priority() == 2) {
            state.add_job(m_job);
            state.schedule_job(SystemState::JobQueue::Hold2, m_job.get_number());
        } else {
            throw runtime_error("Error: Invalid job priority.");
        }
    } else {
        state.allocate_memory(m_job.get_max_memory());
        state.add_job(m_job);
        state.schedule_job(SystemState::JobQueue::Ready, m_job.get_number());
    }
}

Event::Type JobArrivalEvent::get_type() const {
    return Event::Type::External;
}

