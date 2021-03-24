

#define NULL_PTR  ((void *)0)

int IsReadingWithinMaxDelta_Return_0(double value, double nextValue, double maxDelta);

int Validate_Sensor_Readings(double* values, int numOfValues, double MaxDeltaValue);

int IsValidSensorInputwithinRange_Return_0(double* Senosor_Values, int NumOfValues, double MaxDeltaValue);

int IsSensorInputBreached_Return_1(double* Senosor_Values)
