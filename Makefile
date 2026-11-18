CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude -O2
SRCS = src/Vehicle.cpp \
       src/Lane.cpp \
       src/Intersection.cpp \
       src/TrafficGenerator.cpp \
       src/MetricsTracker.cpp \
       src/SimulationEngine.cpp \
       src/main.cpp

TARGET = traffic_simulation

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET) *.exe

