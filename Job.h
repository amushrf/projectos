#ifndef _JOB_H_
#define _JOB_H_

/**
 * @brief The Job class represents a job in a scheduling simulator.
 */
class Job {
public:
    /**
     * @brief Constructs a Job object with the specified attributes.
     * @param arrival_time The arrival time of the job.
     * @param number The job number.
     * @param max_memory The maximum memory required by the job.
     * @param max_devices The maximum number of devices required by the job.
     * @param runtime The runtime of the job.
     * @param priority The priority of the job.
     */
    Job(int arrival_time, int number, int max_memory, int max_devices, int runtime, int priority);
    
    /**
     * @brief Gets the arrival time of the job.
     * @return The arrival time.
     */
    int get_arrival_time() const;
    
    /**
     * @brief Gets the job number.
     * @return The job number.
     */
    int get_number() const;
    
    /**
     * @brief Gets the maximum memory required by the job.
     * @return The maximum memory.
     */
    int get_max_memory() const;
    
    /**
     * @brief Gets the maximum number of devices required by the job.
     * @return The maximum number of devices.
     */
    int get_max_devices() const;
    
    /**
     * @brief Gets the runtime of the job.
     * @return The runtime.
     */
    int get_runtime() const;
    
    /**
     * @brief Gets the priority of the job.
     * @return The priority.
     */
    int get_priority() const;
    
    /**
     * @brief Gets the number of devices allocated to the job.
     * @return The number of allocated devices.
     */
    int get_allocated_devices() const;
    
    /**
     * @brief Sets the number of devices allocated to the job.
     * @param allocated_devices The number of allocated devices.
     */
    void set_allocated_devices(int allocated_devices);
    
    /**
     * @brief Gets the number of devices requested by the job.
     * @return The number of requested devices.
     */
    int get_requested_devices() const;
    
    /**
     * @brief Sets the number of devices requested by the job.
     * @param requested_devices The number of requested devices.
     */
    void set_requested_devices(int requested_devices);
    
    /**
     * @brief Allocates the requested devices to the job.
     */
    void allocate_requested_devices();
    
    /**
     * @brief Releases the specified number of devices from the job.
     * @param devices The number of devices to release.
     */
    void release_devices(int devices);
    
    /**
     * @brief Gets the remaining time for the job to complete.
     * @return The remaining time.
     */
    int get_time_remaining() const;
    
    /**
     * @brief Sets the remaining time for the job to complete.
     * @param time_remaining The remaining time.
     */
    void set_time_remaining(int time_remaining);
    
    /**
     * @brief Steps the time for the job by the specified amount.
     * @param time The amount of time to step.
     */
    void step_time(int time);
    
    int get_accrued_time() const;
    
    void set_accrued_time(int runtime, int time_remaining);
    /**
     * @brief Gets the completion time of the job.
     * @return The completion time.
     */
    int get_completion_time() const;
    
    /**
     * @brief Sets the completion time of the job.
     * @param time The completion time.
     */
    void set_completion_time(int time);
    
private:
    int m_arrival_time;
    int m_number;
    int m_max_memory;
    int m_max_devices;
    int m_runtime;
    int m_priority;
    
    int m_allocated_devices;
    int m_time_remaining;
    int m_accrued_time;
    int m_requested_devices;
    int m_completion_time;
};

static const int NoJob = -1;

#endif // _JOB_H_
