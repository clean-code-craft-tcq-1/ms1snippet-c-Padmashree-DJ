#include "sensor-validate.h"
#include <cstddef>

double Senosor_Values_NULL[]={NULL};

int IsReadingWithinMaxDelta_Return_0(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return 0;
  }
  return 1;
}

int IsSensorInputBreached_Return_1(double* Senosor_Values)
{
 if (Senosor_Values !=Senosor_Values_NULL)
 {
	 return 0;
 }
 else 
 {
	 return 1;
 }
}

int IsValidSensorInputwithinRange_Return_0(double* Senosor_Values, int NumOfValues, double MaxDeltaValue)
{
	int SensorArrayValueIndex=0;
	for( SensorArrayValueIndex=0; SensorArrayValueIndex< (NumOfValues-1); SensorArrayValueIndex++)
	{
		if(!IsReadingWithinMaxDelta_Return_0(Senosor_Values[SensorArrayValueIndex], Senosor_Values[SensorArrayValueIndex+1],MaxDeltaValue))
		{
			return 0;
		}
	}
	return 1;
}
int Validate_Sensor_Readings(double* Senosor_Values, int NumOfValues, double MaxDeltaValue )
{
	int RetVal=IsSensorInputBreached_Return_1(Senosor_Values);
	if (RetVal==0)
	{
		RetVal= IsValidSensorInputwithinRange_Return_0(Senosor_Values, NumOfValues, MaxDeltaValue);
	}
	else
	{
		//do nothing
	}
	return RetVal;
}
	
	
	
	
	