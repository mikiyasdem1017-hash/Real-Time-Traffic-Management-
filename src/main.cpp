#include "Intersection.h"
#include "TrafficGenerator.h"
#include "MetricsTracker.h"
#include "SimulationEngine.h"
#include <iostream>

int main() {
    std::cout << "==============================================================\n";
    std::cout << "    REAL-TIME TRAFFIC MANAGEMENT SYSTEM (GREEDY ALGORITHM)    \n";
    std::cout << "==============================================================\n";
    std::cout << "Architecture: Modular Object-Oriented C++ (C++17)\n";
    std::cout << "Greedy Policy: Dynamically allocate GREEN light to the lane\n";
    std::cout << "               with the longest waiting queue.\n";
    std::cout << "--------------------------------------------------------------\n\n";

    // 1. Initialize Intersection and directional lanes
    Intersection intersection;
    intersection.addLane("Northbound");
    intersection.addLane("Southbound");
    intersection.addLane("Eastbound");
    intersection.addLane("Westbound");

    // 2. Initialize Traffic Generator
    // Parameters: arrivalProbability = 0.65, maxVehiclesPerLane = 2, seed = 1337
    TrafficGenerator trafficGenerator(0.65, 2, 1337);

    // 3. Initialize Metrics Tracker
    MetricsTracker metricsTracker;

    // 4. Initialize Simulation Engine
    // Parameters: intersection, trafficGenerator, metricsTracker, dischargeRate = 2 vehicles/step
    const int DISCHARGE_RATE = 2;
    SimulationEngine engine(intersection, trafficGenerator, metricsTracker, DISCHARGE_RATE);

    // 5. Execute Simulation
    const int TOTAL_SIMULATION_STEPS = 15;
    std::cout << "Starting simulation for " << TOTAL_SIMULATION_STEPS << " time steps...\n";
    engine.run(TOTAL_SIMULATION_STEPS);

    std::cout << "Simulation successfully completed.\n";
    return 0;
}

