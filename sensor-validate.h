#include <cstddef>
#include <math.h>
#include <stdlib.h>


typedef struct
{
    double SOCMaxDeltaValue;
	double CurrentMaxDeltaValue;
}MaxJumpType;
    
int IsSensorInputBreached_Return_1(double* Senosor_Values,int NumOfValues);
int IsSensorReadinginput_NotaNumber(double* Senosor_Values,int NumOfValues);
int IsValidSensorInputwithinRange_Return_0(double* Senosor_Values, int NumOfValues, double MaxDeltaValue);
int Validate_Sensor_Readings(double* values, int numOfValues, double MaxDeltaValue);




