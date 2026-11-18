#pragma once

#include "Intersection.h"
#include "Vehicle.h"
#include <random>

/**
 * @brief Simulates incoming traffic flow by generating Vehicle instances randomly
 *        and assigning them to lanes at each simulation time step.
 */
class TrafficGenerator {
private:
    int m_nextVehicleId;
    double m_arrivalProbability;
    int m_maxVehiclesPerLane;
    std::mt19937 m_rng;
    std::uniform_real_distribution<double> m_probDist;
    std::uniform_int_distribution<int> m_countDist;

public:
    /**
     * @brief Constructs a TrafficGenerator.
     * @param arrivalProbability Chance (0.0 to 1.0) that new vehicles arrive in any given lane per step.
     * @param maxVehiclesPerLane Maximum number of vehicles that can arrive at a lane in a single step.
     * @param seed Random seed for reproducible or non-deterministic simulations.
     */
    explicit TrafficGenerator(double arrivalProbability = 0.65, 
                              int maxVehiclesPerLane = 2, 
                              unsigned int seed = 42);

    /**
     * @brief Generates random vehicle arrivals and enqueues them into lanes.
     * @param intersection Reference to the Intersection being populated.
     * @param currentTime Current simulation clock / time step.
     * @return Total number of vehicles generated in this time step.
     */
    int generateTraffic(Intersection& intersection, int currentTime);

    /**
     * @brief Gets the next vehicle ID to be assigned.
     * @return Next integer ID.
     */
    int getNextVehicleId() const;
};

