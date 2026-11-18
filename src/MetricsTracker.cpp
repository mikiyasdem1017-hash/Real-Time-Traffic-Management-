#include "MetricsTracker.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

MetricsTracker::MetricsTracker()
    : m_totalVehiclesProcessed(0),
      m_totalWaitTime(0),
      m_maxWaitTime(0),
      m_minWaitTime(std::numeric_limits<int>::max()) {}

void MetricsTracker::recordVehicle(const Vehicle& vehicle) {
    int wait = vehicle.getWaitTime();
    m_totalVehiclesProcessed++;
    m_totalWaitTime += wait;
    m_maxWaitTime = std::max(m_maxWaitTime, wait);
    m_minWaitTime = std::min(m_minWaitTime, wait);
}

int MetricsTracker::getTotalVehiclesProcessed() const {
    return m_totalVehiclesProcessed;
}

int MetricsTracker::getTotalWaitTime() const {
    return m_totalWaitTime;
}

double MetricsTracker::getAverageWaitTime() const {
    if (m_totalVehiclesProcessed == 0) {
        return 0.0;
    }
    return static_cast<double>(m_totalWaitTime) / m_totalVehiclesProcessed;
}

int MetricsTracker::getMaxWaitTime() const {
    return (m_totalVehiclesProcessed == 0) ? 0 : m_maxWaitTime;
}

int MetricsTracker::getMinWaitTime() const {
    return (m_totalVehiclesProcessed == 0) ? 0 : m_minWaitTime;
}

void MetricsTracker::printReport(int totalSteps, size_t remainingVehicles) const {
    std::cout << "\n======================================================\n";
    std::cout << "       REAL-TIME TRAFFIC SIMULATION PERFORMANCE REPORT\n";
    std::cout << "======================================================\n";
    std::cout << std::left << std::setw(34) << " Total Simulation Steps:" 
              << totalSteps << " steps\n";
    std::cout << std::left << std::setw(34) << " Total Vehicles Processed:" 
              << m_totalVehiclesProcessed << "\n";
    std::cout << std::left << std::setw(34) << " Vehicles Remaining in Queue:" 
              << remainingVehicles << "\n";
    std::cout << std::left << std::setw(34) << " Cumulative Wait Time:" 
              << m_totalWaitTime << " time units\n";

    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::left << std::setw(34) << " Average Wait Time per Vehicle:" 
              << getAverageWaitTime() << " time units\n";
    std::cout << std::left << std::setw(34) << " Minimum Wait Time:" 
              << getMinWaitTime() << " time units\n";
    std::cout << std::left << std::setw(34) << " Maximum Wait Time:" 
              << getMaxWaitTime() << " time units\n";

    double throughput = (totalSteps > 0) 
                        ? static_cast<double>(m_totalVehiclesProcessed) / totalSteps 
                        : 0.0;
    std::cout << std::left << std::setw(34) << " System Throughput:" 
              << throughput << " vehicles/step\n";
    std::cout << "======================================================\n\n";
}

