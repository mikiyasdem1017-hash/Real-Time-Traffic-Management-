
#include "TrafficGenerator.h"
#include <random>

using namespace std;

// Constructor
TrafficGenerator::TrafficGenerator(int maxVehicles) {
    nextVehicleId = 1;
    maxVehiclesPerStep = maxVehicles;

    random_device rd;
    randomEngine.seed(rd());
}

// Generate a random direction
int TrafficGenerator::generateDirection() {
    uniform_int_distribution<int> direction(0, 3);

    // 0 = North
    // 1 = South
    // 2 = East
    // 3 = West

    return direction(randomEngine);
}

// Generate one vehicle
Vehicle TrafficGenerator::generateVehicle() {
    int direction = generateDirection();

    // Assumes Vehicle has a constructor:
    // Vehicle(int id, int direction)
    Vehicle vehicle(nextVehicleId, direction);

    nextVehicleId++;

    return vehicle;
}

// Generate vehicles for one time step
vector<Vehicle> TrafficGenerator::generateVehicles() {
    vector<Vehicle> vehicles;

    uniform_int_distribution<int> arrivalCount(
        0, maxVehiclesPerStep
    );

    int numberOfVehicles = arrivalCount(randomEngine);

    for (int i = 0; i < numberOfVehicles; i++) {
        vehicles.push_back(generateVehicle());
    }

    return vehicles;
}
