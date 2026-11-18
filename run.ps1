$compiler = "C:\Program Files (x86)\Dev-Cpp\MinGW64\bin\g++.exe"
if (-not (Test-Path $compiler)) {
    $compiler = "g++"
}

Write-Host "==> Compiling Real-Time Traffic Simulation..." -ForegroundColor Cyan
& $compiler -std=c++11 -Wall -Wextra -Iinclude src/Vehicle.cpp src/Lane.cpp src/Intersection.cpp src/TrafficGenerator.cpp src/MetricsTracker.cpp src/SimulationEngine.cpp src/main.cpp -o traffic_simulation.exe

if ($LASTEXITCODE -eq 0) {
    Write-Host "==> Launching Simulation..." -ForegroundColor Green
    Write-Host ""
    .\traffic_simulation.exe
} else {
    Write-Host "Compilation failed." -ForegroundColor Red
}

