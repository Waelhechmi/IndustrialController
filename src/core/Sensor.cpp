#include "Sensor.hpp"

Sensor::Sensor(const std::string& name)
    : name_(name), value_(0.0) {}

void Sensor::setValue(double value) {
    value_ = value;
}

double Sensor::getValue() const {
    return value_;
}

std::string Sensor::getName() const {
    return name_;
}
