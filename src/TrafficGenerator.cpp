#include "TrafficGenerator.h"

TrafficGenerator::TrafficGenerator(double arrivalProbability, int maxVehiclesPerLane, unsigned int seed)
    : m_nextVehicleId(1),
      m_arrivalProbability(arrivalProbability),
      m_maxVehiclesPerLane(maxVehiclesPerLane),
      m_rng(seed),
      m_probDist(0.0, 1.0),
      m_countDist(1, maxVehiclesPerLane) {}

int TrafficGenerator::generateTraffic(Intersection& intersection, int currentTime) {
    int totalGenerated = 0;

    for (auto& lane : intersection.getLanes()) {
        // Roll to see if vehicles arrive at this lane during this time step
        if (m_probDist(m_rng) < m_arrivalProbability) {
            int vehiclesToCreate = m_countDist(m_rng);
            for (int i = 0; i < vehiclesToCreate; ++i) {
                Vehicle newVehicle(m_nextVehicleId++, currentTime);
                lane.addVehicle(newVehicle);
                totalGenerated++;
            }
        }
    }

    return totalGenerated;
}

int TrafficGenerator::getNextVehicleId() const {
    return m_nextVehicleId;
}

