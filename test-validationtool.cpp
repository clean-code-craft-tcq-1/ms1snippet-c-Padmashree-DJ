#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "sensor-validate.h"


MaxJumpType MaxDeltaValues={
	0.05,
	0.1
};
TEST_CASE("reports error when soc jumps abruptly") {
  double socReadings[] = {0.0, 0.01, 0.5, 0.51};
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  REQUIRE(Validate_Sensor_Readings(socReadings, numOfSocReadings, MaxDeltaValues.SOCMaxDeltaValue) == 0);
}

TEST_CASE("reports error when current jumps abruptly") {
  double currentReadings[] = {0.0, 0.02, 0.03, 0.33};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(Validate_Sensor_Readings(currentReadings, numOfCurReadings, MaxDeltaValues.CurrentMaxDeltaValue) == 0);
}

TEST_CASE("reports error when Readings are not entered") {
  double SensorReadings[] = {NULL};
  int numOfReadings = sizeof(SensorReadings) / sizeof(SensorReadings[0]);
  REQUIRE(Validate_Sensor_Readings(SensorReadings, numOfReadings, MaxDeltaValues.CurrentMaxDeltaValue) == 1);
}

TEST_CASE("reports error when Reading entered is not a number") {
  double SensorReadings[] = {0.0, NAN, 0.5, 0.51};
  int numOfReadings = sizeof(SensorReadings) / sizeof(SensorReadings[0]);
  REQUIRE(Validate_Sensor_Readings(SensorReadings, numOfReadings, MaxDeltaValues.CurrentMaxDeltaValue) == NAN);
}

TEST_CASE("reports error when number of elments in array is miscalculated") {
  double SensorReadings[] = {0.0, 0, 0.5, 0.51};
  int numOfReadings = NAN;
  REQUIRE(Validate_Sensor_Readings(SensorReadings, numOfReadings, MaxDeltaValues.CurrentMaxDeltaValue) == NAN);
}

TEST_CASE("reports error when Reading entered is not a number and number of elments in array is miscalculated") {
  double SensorReadings[] = {0.0, NAN, 0.5, 0.51};
  int numOfReadings = NAN;
  REQUIRE(Validate_Sensor_Readings(SensorReadings, numOfReadings, MaxDeltaValues.CurrentMaxDeltaValue) == NAN);
}