#pragma once

#include "Lane.h"
#include <vector>

/**
 * @brief Represents a traffic intersection containing multiple directional lanes.
 *        Employs a Greedy Algorithm to select the optimal lane for green light allocation.
 */
class Intersection {
private:
    std::vector<Lane> m_lanes;

public:
    Intersection() = default;

    /**
     * @brief Adds a new Lane to the intersection.
     * @param lane The Lane object to add.
     */
    void addLane(const Lane& lane);

    /**
     * @brief Convenience overload to add a Lane by direction name.
     * @param direction Name of the direction (e.g. "Northbound").
     */
    void addLane(std::string direction);

    /**
     * @brief Evaluates all lanes using a Greedy Strategy and selects the lane
     *        with the largest queue length to receive a green light.
     * @return Pointer to the optimal Lane, or nullptr if all lanes are empty.
     */
    Lane* getOptimalGreedyLane();

    /**
     * @brief Gets a mutable reference to the collection of lanes.
     * @return Reference to vector of Lane objects.
     */
    std::vector<Lane>& getLanes();

    /**
     * @brief Gets a const reference to the collection of lanes.
     * @return Const reference to vector of Lane objects.
     */
    const std::vector<Lane>& getLanes() const;

    /**
     * @brief Calculates total number of vehicles queued across all lanes.
     * @return Total queue count.
     */
    size_t getTotalQueueLength() const;
};

