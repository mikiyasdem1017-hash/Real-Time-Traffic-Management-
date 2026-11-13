#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Vehicle
{
private:
    int id;
    string type;
    int arrivalTime;
    int priority;

public:
    // Constructor
    Vehicle(int id, string type, int arrivalTime, int priority);

    // Getter functions
    int getId();
    string getType();
    int getArrivalTime();
    int getPriority();
};

#endif