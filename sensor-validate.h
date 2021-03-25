#include <cstddef>
#include <math.h>
#include <stdlib.h>

#define NULL_PTR (void*)0

typedef struct
{
    double SOCMaxDeltaValue;
	double CurrentMaxDeltaValue;
}MaxJumpType;
    
int IsSensorInputBreached_Return_1(double* Senosor_Values,int NumOfValues);
int IsSensorReadinginput_NotaNumber(double* Senosor_Values,int NumOfValues);
int IsValidSensorInputwithinRange_Return_0(double* Senosor_Values, int NumOfValues, double MaxDeltaValue);
int Validate_Sensor_Readings(double* values, int numOfValues, double MaxDeltaValue);




