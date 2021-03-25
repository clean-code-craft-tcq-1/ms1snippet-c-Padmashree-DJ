#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "sensor-validate.h"


typedef enum
{
    SOCMaxDeltaValue = 0.05,
	CurrentMaxDeltaValue =0.1
}MaxJumpType;
    
TEST_CASE("reports error when soc jumps abruptly") {
  double socReadings[] = {0.0, 0.01, 0.5, 0.51};
  // double SOCMaxDeltaValue=0.05;
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  REQUIRE(Validate_Sensor_Readings(socReadings, numOfSocReadings, (double)SOCMaxDeltaValue) == 0);
}

TEST_CASE("reports error when current jumps abruptly") {
  double currentReadings[] = {0.0, 0.02, 0.03, 0.33};
  // double CurrentMaxDeltaValue= 0.1;
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(Validate_Sensor_Readings(currentReadings, numOfCurReadings, (double)CurrentMaxDeltaValue) == 0);
}

TEST_CASE("reports error when Readings are not entered") {
  double SensorReadings[] = {NULL};
  double SensorMaxDeltaValue= 0.1;
  int numOfReadings = sizeof(SensorReadings) / sizeof(SensorReadings[0]);
  REQUIRE(Validate_Sensor_Readings(SensorReadings, numOfReadings, SensorMaxDeltaValue) == 1);
}

