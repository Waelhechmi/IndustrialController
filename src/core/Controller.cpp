#include "Controller.hpp"

bool Controller::isOverLimit(double value) const {
    return value > 100.0;
}
