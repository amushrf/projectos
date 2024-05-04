#include <iostream>
#include <stdexcept>
#include <vector>

#include "DeviceReleaseEvent.h"
#include "SystemState.h"

using namespace std;

DeviceReleaseEvent::DeviceReleaseEvent(int time, int job_number, 
                                       int released_devices)
: Event(time), m_job_number(job_number), 
  m_released_devices(released_devices) {
}
    
/**
 * @brief Processes the device release event.
 *
 * This function is responsible for releasing the devices associated with the current job on the CPU.
 * It checks if the current job is on the CPU and releases the devices accordingly.
 * If the job is not on the CPU, it prints an error message and returns.
 * After releasing the devices, it ends the current quantum.
 *
 * @param state The system state object.
 */
void DeviceReleaseEvent::process(SystemState& state) {
    cout << get_time() << ": Release for devices" << endl;
    if (state.cpu_get_job() != m_job_number) {
        cerr << " Error: Job attempted to release devices while not on the CPU"
             << endl;
        return;
    }
    
    state.cpu_release_devices(m_released_devices);
    state.end_quantum();
}

Event::Type DeviceReleaseEvent::get_type() const {
    return Event::Type::External;
}
