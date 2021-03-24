#include "sensor-validate.h"

double* Senosor_Values_NULL[]={NULL};

int IsReadingWithinMaxDelta_Return_0(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return 0;
  }
  return 1;
}

int Validate_Sensor_Readings(double* Senosor_Values, int NumOfValues, double MaxDeltaValue )
{
	int SensorArrayValueIndex=0;
	for( SensorArrayValueIndex=0; SensorArrayValueIndex< (NumOfValues-1); SensorArrayValueIndex++)
	{
		if((Senosor_Values!= Senosor_Values_NULL) &&(!IsReadingWithinMaxDelta_Return_0(Senosor_Values[SensorArrayValueIndex], Senosor_Values[SensorArrayValueIndex+1],MaxDeltaValue)))
		{
			return 0;
		}
	}
	return 1;
}
	
	