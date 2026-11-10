#pragma once

#include <iostream>

/**
 * @brief Represents an individual vehicle within the traffic simulation.
 */
class Vehicle {
private:
    int m_id;
    int m_arrivalTime;
    int m_waitTime;

public:
    /**
     * @brief Constructs a new Vehicle instance.
     * @param id Unique identifier for the vehicle.
     * @param arrivalTime Time step at which the vehicle entered a lane.
     */
    Vehicle(int id, int arrivalTime);

    // Getters
    int getId() const;
    int getArrivalTime() const;
    int getWaitTime() const;

    /**
     * @brief Increments the vehicle's wait time by a specified delta.
     * @param delta Amount of time steps to increment (default is 1).
     */
    void incrementWaitTime(int delta = 1);
};

