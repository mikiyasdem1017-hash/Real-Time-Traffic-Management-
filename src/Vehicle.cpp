#include "Vehicle.h"

Vehicle::Vehicle(int id, int arrivalTime)
    : m_id(id), m_arrivalTime(arrivalTime), m_waitTime(0) {}

int Vehicle::getId() const {
    return m_id;
}

int Vehicle::getArrivalTime() const {
    return m_arrivalTime;
}

int Vehicle::getWaitTime() const {
    return m_waitTime;
}

void Vehicle::incrementWaitTime(int delta) {
    if (delta > 0) {
        m_waitTime += delta;
    }
}

