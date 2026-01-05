#include <gtest/gtest.h>
#include "../src/core/Sensor.hpp"

TEST(SensorTest, GetSetValue) {
    Sensor s("Temp");
    s.setValue(75.5);
    EXPECT_DOUBLE_EQ(s.getValue(), 75.5);
    EXPECT_EQ(s.getName(), "Temp");
}
