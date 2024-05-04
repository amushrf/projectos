#include "Event.h"

Event::Event(int time) 
: m_time(time) { 
}

Event::~Event() {
}

int Event::get_time() const {
    return m_time;
}

/**
 * @brief Overloaded less than operator for comparing two Event objects.
 * 
 * This operator compares two Event objects based on their time and type.
 * If the time of the current Event object is less than the time of the other Event object,
 * it returns true. If the times are equal, it checks if the type of the current Event object
 * is Type::Internal and the type of the other Event object is Type::External. If this condition
 * is true, it returns true; otherwise, it returns false.
 * 
 * @param other The Event object to compare with.
 * @return true if the current Event object is less than the other Event object, false otherwise.
 */
bool Event::operator< (const Event& other) const {
    if (this->get_time() != other.get_time()) {
        return this->get_time() < other.get_time();
    } else {
        return this->get_type() == Type::Internal && other.get_type() == Type::External;
    }
}
