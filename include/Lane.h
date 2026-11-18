#pragma once

#include "Vehicle.h"
#include <string>
#include <queue>
#include <stdexcept>

/**
 * @brief Manages a single traffic lane with a specific direction and a vehicle FIFO queue.
 */
class Lane {
private:
    std::string m_direction;
    std::queue<Vehicle> m_vehicleQueue;

public:
    /**
     * @brief Constructs a Lane with a designated direction.
     * @param direction Name of the direction (e.g., "Northbound", "Eastbound").
     */
    explicit Lane(std::string direction);

    /**
     * @brief Adds a vehicle to the back of the lane's queue.
     * @param vehicle The Vehicle instance to add.
     */
    void addVehicle(const Vehicle& vehicle);

    /**
     * @brief Removes and returns the vehicle at the front of the queue.
     * @return The removed Vehicle instance.
     * @throws std::runtime_error if the queue is empty.
     */
    Vehicle removeVehicle();

    /**
     * @brief Returns the number of vehicles currently waiting in the lane.
     * @return Total queue size.
     */
    size_t getQueueSize() const;

    /**
     * @brief Checks if the lane has no waiting vehicles.
     * @return True if empty, false otherwise.
     */
    bool isEmpty() const;

    /**
     * @brief Retrieves the direction name of the lane.
     * @return Const reference to direction string.
     */
    const std::string& getDirection() const;

    /**
     * @brief Increments wait time for all vehicles currently queued in this lane.
     * @param delta Amount of time steps to increment (default is 1).
     */
    void updateWaitTimes(int delta = 1);

    /**
     * @brief Peeks at the front vehicle without removing it.
     * @return Const reference to the front Vehicle.
     * @throws std::runtime_error if the queue is empty.
     */
    const Vehicle& peekFrontVehicle() const;
};

