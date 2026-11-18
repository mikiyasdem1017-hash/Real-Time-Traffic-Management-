#include "SimulationEngine.h"
#include <iostream>
#include <iomanip>
#include <vector>

SimulationEngine::SimulationEngine(Intersection& intersection,
                                   TrafficGenerator& generator,
                                   MetricsTracker& tracker,
                                   int dischargeRate)
    : m_intersection(intersection),
      m_trafficGenerator(generator),
      m_metricsTracker(tracker),
      m_dischargeRate(dischargeRate),
      m_currentTime(1) {}

void SimulationEngine::step() {
    std::cout << "\n------------------------------------------------------------\n";
    std::cout << ">>> SIMULATION TIME STEP: " << m_currentTime << "\n";
    std::cout << "------------------------------------------------------------\n";

    // 1. Generate new incoming traffic
    int arrivals = m_trafficGenerator.generateTraffic(m_intersection, m_currentTime);
    std::cout << "[Arrivals] " << arrivals << " new vehicle(s) arrived at the intersection.\n";

    // Display current queue status across all lanes
    std::cout << "[Queue Status Before Signal]:\n";
    for (const auto& lane : m_intersection.getLanes()) {
        std::cout << "  - " << std::left << std::setw(15) << (lane.getDirection() + ":")
                  << lane.getQueueSize() << " vehicle(s) waiting\n";
    }

    // 2. Greedy Light Controller Selection
    Lane* optimalLane = m_intersection.getOptimalGreedyLane();

    if (optimalLane != nullptr && !optimalLane->isEmpty()) {
        std::cout << "[Greedy Choice] Lane \"" << optimalLane->getDirection() 
                  << "\" selected (Largest Queue: " << optimalLane->getQueueSize() << ")\n";
        std::cout << "[Signal State] GREEN: " << optimalLane->getDirection() 
                  << " | RED: All other lanes\n";

        // 3. Discharge vehicles from selected green lane up to dischargeRate
        int dischargedCount = 0;
        std::vector<Vehicle> clearedVehicles;

        while (!optimalLane->isEmpty() && dischargedCount < m_dischargeRate) {
            Vehicle v = optimalLane->removeVehicle();
            clearedVehicles.push_back(v);
            m_metricsTracker.recordVehicle(v);
            dischargedCount++;
        }

        std::cout << "[Discharge] " << dischargedCount << " vehicle(s) passed the intersection:\n";
        for (const auto& v : clearedVehicles) {
            std::cout << "    * Vehicle ID: #" << v.getId() 
                      << " (Arrived: t=" << v.getArrivalTime() 
                      << ", Total Wait: " << v.getWaitTime() << " steps)\n";
        }
    } else {
        std::cout << "[Signal State] ALL RED / IDLE - No vehicles currently waiting in any lane.\n";
    }

    // 4. Update wait times for all vehicles remaining in queues
    for (auto& lane : m_intersection.getLanes()) {
        lane.updateWaitTimes(1);
    }

    m_currentTime++;
}

void SimulationEngine::run(int totalSteps) {
    for (int i = 0; i < totalSteps; ++i) {
        step();
    }

    // Output final analytics report
    m_metricsTracker.printReport(totalSteps, m_intersection.getTotalQueueLength());
}

int SimulationEngine::getCurrentTime() const {
    return m_currentTime;
}

