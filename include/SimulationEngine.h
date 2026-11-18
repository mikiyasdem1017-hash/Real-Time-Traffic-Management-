#pragma once

#include "Intersection.h"
#include "TrafficGenerator.h"
#include "MetricsTracker.h"

/**
 * @brief Coordinates the discrete-event, time-stepped simulation.
 *        Orchestrates traffic generation, greedy lane selection, vehicle processing,
 *        queue wait-time updates, and step-by-step reporting.
 */
class SimulationEngine {
private:
    Intersection& m_intersection;
    TrafficGenerator& m_trafficGenerator;
    MetricsTracker& m_metricsTracker;
    int m_dischargeRate;
    int m_currentTime;

public:
    /**
     * @brief Constructs the SimulationEngine.
     * @param intersection Reference to the intersection model.
     * @param generator Reference to the traffic generator.
     * @param tracker Reference to the metrics tracker.
     * @param dischargeRate Maximum vehicles that can pass through the green lane per step.
     */
    SimulationEngine(Intersection& intersection,
                     TrafficGenerator& generator,
                     MetricsTracker& tracker,
                     int dischargeRate = 2);

    /**
     * @brief Executes a single time step of the simulation.
     */
    void step();

    /**
     * @brief Executes the simulation loop for a given number of steps.
     * @param totalSteps Number of time steps to run.
     */
    void run(int totalSteps);

    /**
     * @brief Gets current simulation clock step.
     */
    int getCurrentTime() const;
};

