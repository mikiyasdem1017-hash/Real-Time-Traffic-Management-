@echo off
set "PATH=C:\Program Files (x86)\Dev-Cpp\MinGW64\bin;%PATH%"

echo [1/2] Compiling Traffic Simulation...
g++ -std=c++11 -Wall -Wextra -Iinclude src/Vehicle.cpp src/Lane.cpp src/Intersection.cpp src/TrafficGenerator.cpp src/MetricsTracker.cpp src/SimulationEngine.cpp src/main.cpp -o traffic_simulation.exe

if %ERRORLEVEL% equ 0 (
    echo [2/2] Running Traffic Simulation...
    echo.
    traffic_simulation.exe
) else (
    echo Compilation failed with error code %ERRORLEVEL%.
)
pause

