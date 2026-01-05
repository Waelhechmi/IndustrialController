// src/core/AlarmManager.hpp
#pragma once
#include <string>
#include "Sensor.hpp"

enum class SystemState {
    NORMAL,
    WARNING,
    ERROR
};

class AlarmManager {
public:
    AlarmManager(double warningThreshold, double errorThreshold);

    SystemState checkSensor(const Sensor& sensor);
    std::string stateToString(SystemState state) const;

private:
    double warningThreshold_;
    double errorThreshold_;
};
