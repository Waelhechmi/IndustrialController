#include <gtest/gtest.h>
#include "../src/core/Sensor.hpp"
#include "../src/core/AlarmManager.hpp"

// Test seuil NORMAL
TEST(AlarmManagerTest, NormalState) {
    Sensor s("Temp");
    s.setValue(50.0);
    AlarmManager alarm(90.0, 120.0);

    EXPECT_EQ(alarm.checkSensor(s), SystemState::NORMAL);
}

// Test seuil WARNING
TEST(AlarmManagerTest, WarningState) {
    Sensor s("Temp");
    s.setValue(100.0);
    AlarmManager alarm(90.0, 120.0);

    EXPECT_EQ(alarm.checkSensor(s), SystemState::WARNING);
}

// Test seuil ERROR
TEST(AlarmManagerTest, ErrorState) {
    Sensor s("Temp");
    s.setValue(130.0);
    AlarmManager alarm(90.0, 120.0);

    EXPECT_EQ(alarm.checkSensor(s), SystemState::ERROR);
}
