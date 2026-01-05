// src/core/AlarmManager.cpp
#include "AlarmManager.hpp"

AlarmManager::AlarmManager(double warningThreshold, double errorThreshold)
    : warningThreshold_(warningThreshold), errorThreshold_(errorThreshold) {}

SystemState AlarmManager::checkSensor(const Sensor& sensor) {
    double value = sensor.getValue();

    if (value >= errorThreshold_) {
        return SystemState::ERROR;
    } else if (value >= warningThreshold_) {
        return SystemState::WARNING;
    } else {
        return SystemState::NORMAL;
    }
}

std::string AlarmManager::stateToString(SystemState state) const {
    switch (state) {
        case SystemState::NORMAL: return "NORMAL";
        case SystemState::WARNING: return "WARNING";
        case SystemState::ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}
