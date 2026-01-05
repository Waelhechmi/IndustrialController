# IndustrialController

**Industrial Controller Simulator with C++ and Qt GUI**

![Dashboard Screenshot](screenshot.png)

## Description

This project simulates an industrial controller system with a **dashboard-style GUI**. It includes:

- **Graphical dashboard interface** with gauges, progress bars, LCD displays, and warning indicators (inspired by automotive dashboards).  
- **Core modules** for sensors, alarms, and controller logic implemented in modern C++.  
- **Automated unit testing** using Google Test for reliability and correctness.  
- **Extensible design** for adding more sensors, controllers, and GUI features.  

This project is ideal for **educational purposes, engineering projects, or industrial software prototyping**.

---

## Project Structure


IndustrialController/
├── src/ # Source code
│ ├── core/ # Sensor, AlarmManager, Controller
│ └── gui/ # Qt GUI files
├── test/ # Google Test unit tests
├── build/ # Build directory (ignored by git)
├── build_tests/ # Build directory for tests (ignored by git)
├── CMakeLists.txt # Main CMake configuration
└── README.md


# Go to test build folder
cd ../test/build_tests

# Configure CMake
cmake ..

# Build tests
make

# Run all tests
./runTests



---

## Prerequisites

- Linux (Ubuntu recommended)
- C++17 compatible compiler (g++ >= 9)
- Qt 5 or Qt 6
- CMake >= 3.10
- Google Test (for running automated tests)

---

## Build and Run GUI

```bash
# Create build directory
mkdir -p build && cd build

# Configure with CMake
cmake ..

# Build project
make

# Run GUI
./industrial_controller

