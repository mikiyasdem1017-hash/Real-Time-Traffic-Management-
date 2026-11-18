#include "Intersection.h"

void Intersection::addLane(const Lane& lane) {
    m_lanes.push_back(lane);
}

void Intersection::addLane(std::string direction) {
    m_lanes.emplace_back(std::move(direction));
}

Lane* Intersection::getOptimalGreedyLane() {
    Lane* optimalLane = nullptr;
    size_t maxQueue = 0;

    // Greedy Choice: Locally optimal decision at each step
    // Select the lane with the maximum number of waiting vehicles.
    for (auto& lane : m_lanes) {
        size_t currentQueueSize = lane.getQueueSize();
        if (currentQueueSize > maxQueue) {
            maxQueue = currentQueueSize;
            optimalLane = &lane;
        }
    }

    return optimalLane;
}

std::vector<Lane>& Intersection::getLanes() {
    return m_lanes;
}

const std::vector<Lane>& Intersection::getLanes() const {
    return m_lanes;
}

size_t Intersection::getTotalQueueLength() const {
    size_t total = 0;
    for (const auto& lane : m_lanes) {
        total += lane.getQueueSize();
    }
    return total;
}

