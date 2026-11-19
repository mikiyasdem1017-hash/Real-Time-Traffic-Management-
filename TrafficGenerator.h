
#ifndef TRAFFIC_GENERATOR_H
#define TRAFFIC_GENERATOR_H

#include "Vehicle.h"
#include <vector>
#include <random>

class TrafficGenerator {
private:
    int nextVehicleId;
    int maxVehiclesPerStep;

    std::mt19937 randomEngine;

public:
    // Constructor
    TrafficGenerator(int maxVehicles);

    // Generate a random direction
    int generateDirection();

    // Generate one vehicle
    Vehicle generateVehicle();

    // Generate vehicles for one time step
    std::vector<Vehicle> generateVehicles();
};

#endif
