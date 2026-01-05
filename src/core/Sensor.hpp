#pragma once
#include <string>

class Sensor {
public:
    Sensor(const std::string& name);

    void setValue(double value);
    double getValue() const;
    std::string getName() const;

private:
    std::string name_;
    double value_;
};
