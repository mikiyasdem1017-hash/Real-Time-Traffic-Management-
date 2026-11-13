#include "Vehicle.h"

// Constructor implementation
Vehicle::Vehicle(int id, string type, int arrivalTime, int priority)
{
    this->id = id;
    this->type = type;
    this->arrivalTime = arrivalTime;
    this->priority = priority;
}

// Getter function implementations
int Vehicle::getId()
{
    return id;
}

string Vehicle::getType()
{
    return type;
}

int Vehicle::getArrivalTime()
{
    return arrivalTime;
}

int Vehicle::getPriority()
{
    return priority;
}