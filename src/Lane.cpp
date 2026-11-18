#include "Lane.h"

Lane::Lane(std::string direction)
    : m_direction(std::move(direction)) {}

void Lane::addVehicle(const Vehicle& vehicle) {
    m_vehicleQueue.push(vehicle);
}

Vehicle Lane::removeVehicle() {
    if (m_vehicleQueue.empty()) {
        throw std::runtime_error("Attempted to remove vehicle from an empty lane: " + m_direction);
    }
    Vehicle frontVehicle = m_vehicleQueue.front();
    m_vehicleQueue.pop();
    return frontVehicle;
}

size_t Lane::getQueueSize() const {
    return m_vehicleQueue.size();
}

bool Lane::isEmpty() const {
    return m_vehicleQueue.empty();
}

const std::string& Lane::getDirection() const {
    return m_direction;
}

void Lane::updateWaitTimes(int delta) {
    size_t count = m_vehicleQueue.size();
    for (size_t i = 0; i < count; ++i) {
        Vehicle vehicle = m_vehicleQueue.front();
        m_vehicleQueue.pop();
        vehicle.incrementWaitTime(delta);
        m_vehicleQueue.push(vehicle);
    }
}

const Vehicle& Lane::peekFrontVehicle() const {
    if (m_vehicleQueue.empty()) {
        throw std::runtime_error("Attempted to peek vehicle in an empty lane: " + m_direction);
    }
    return m_vehicleQueue.front();
}

