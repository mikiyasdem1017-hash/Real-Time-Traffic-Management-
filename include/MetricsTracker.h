#pragma once

#include "Vehicle.h"
#include <vector>
#include <limits>

/**
 * @brief Records performance metrics for all vehicles processed through the intersection.
 */
class MetricsTracker {
private:
    int m_totalVehiclesProcessed;
    int m_totalWaitTime;
    int m_maxWaitTime;
    int m_minWaitTime;

public:
    MetricsTracker();

    /**
     * @brief Records the departure of a vehicle and updates aggregated statistics.
     * @param vehicle The Vehicle that has cleared the intersection.
     */
    void recordVehicle(const Vehicle& vehicle);

    // Getters for statistical metrics
    int getTotalVehiclesProcessed() const;
    int getTotalWaitTime() const;
    double getAverageWaitTime() const;
    int getMaxWaitTime() const;
    int getMinWaitTime() const;

    /**
     * @brief Prints a comprehensive, formatted performance report.
     * @param totalSteps Number of simulation steps executed.
     * @param remainingVehicles Number of vehicles still waiting in queues.
     */
    void printReport(int totalSteps, size_t remainingVehicles) const;
};

