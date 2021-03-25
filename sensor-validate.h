#include <cstddef>

#define NULL_PTR  ((void *)0)

int IsSensorInputBreached_Return_1(double* Senosor_Values);
int IsValidSensorInputwithinRange_Return_0(double* Senosor_Values, int NumOfValues, double MaxDeltaValue);
int Validate_Sensor_Readings(double* values, int numOfValues, double MaxDeltaValue);




