#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "sensor-validate.h"


MaxJumpType MaxDeltaValues={
	0.05,
	0.1
};

/*Negative test case */
TEST_CASE("Case for Negative test case :- reports error when soc jumps abruptly") {
  double socReadings[] = {0.0, 0.01, 0.5, 0.51};
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  REQUIRE(Validate_Sensor_Readings(socReadings, numOfSocReadings, MaxDeltaValues.SOCMaxDeltaValue) == 1);
}
/*Positive test case */
TEST_CASE("Case for Positive test case :-reports error when soc jumps abruptly") {
  double socReadings[] = {0.0, 0.01, 0.05, 0.06};
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  REQUIRE(Validate_Sensor_Readings(socReadings, numOfSocReadings, MaxDeltaValues.SOCMaxDeltaValue) == 0);
}

/*Negative test case */
TEST_CASE("Case for Negative test casereports error when current jumps abruptly") {
  double currentReadings[] = {0.0, 0.02, 0.03, 0.33};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(Validate_Sensor_Readings(currentReadings, numOfCurReadings, MaxDeltaValues.CurrentMaxDeltaValue) == 1);
}

/*Positive test case */
TEST_CASE("Case for Positive test case:-reports error when current jumps abruptly") {
  double currentReadings[] = {0.0, 0.02, 0.03, 0.06};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(Validate_Sensor_Readings(currentReadings, numOfCurReadings, MaxDeltaValues.CurrentMaxDeltaValue) == 0);
}

TEST_CASE("reports error when Readings are not entered") {
  double SensorReadings[] = {NULL};
  int numOfReadings = 0;
  REQUIRE(Validate_Sensor_Readings(SensorReadings, numOfReadings, MaxDeltaValues.CurrentMaxDeltaValue) == 1);
}

TEST_CASE("reports error when Reading entered is not a number") {
  double  NaN_it_is = sqrt(-1);
  int its_a_NAN=2;
  double SensorReadings[] = {0.0, NaN_it_is, 0.5, 0.51};
  int numOfReadings = sizeof(SensorReadings) / sizeof(SensorReadings[0]);
  REQUIRE(Validate_Sensor_Readings(SensorReadings, numOfReadings, MaxDeltaValues.CurrentMaxDeltaValue) == its_a_NAN);
}

/* TEST_CASE("reports error when number of elments in array is miscalculated") {
  double SensorReadings[] = {0.0, 0, 0.5, 0.51};
  int numOfReadings = NAN;
  int its_a_NAN=2;
  REQUIRE(Validate_Sensor_Readings(SensorReadings, numOfReadings, MaxDeltaValues.CurrentMaxDeltaValue) == its_a_NAN);
}

TEST_CASE("reports error when Reading entered is not a number and number of elments in array is miscalculated") {
  double SensorReadings[] = {0.0, NAN, 0.5, 0.51};
  int numOfReadings = NAN;
  int its_a_NAN=2;
  REQUIRE(Validate_Sensor_Readings(SensorReadings, numOfReadings, MaxDeltaValues.CurrentMaxDeltaValue) == its_a_NAN);
} */