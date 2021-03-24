#include "sensor-validate.h"

/* /**
 ***************************************************************************************************
 * Function Name: IsReadingWithinMaxDelta_Return_0
 * 
 * Function Description: Checks if the Sensor Reading is within the Jump specified via input parameter maxDelta.
 *
 * \param  Inputs:- double value
 *					double nextValue
 *					double maxDelta
 *					
 *	       Outputs:- None
 *         
 * \return  Integer
 *          
 * \retval  0:- Jump in Sensor Readings is greater than threshold.
 *          1:- Jump in Sensor Reading is less than threshold and valid.
 ***************************************************************************************************
 *
int IsReadingWithinMaxDelta_Return_0(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return 0;
  }
  return 1;
}
 */

/**
 ***************************************************************************************************
 * Function Name: IsSensorInputBreached_Return_1
 * 
 * Function Description: Checks if the Sensor Inputs are not breached and not empty array.
 *
 * \param  Inputs:- double* Senosor_Values
 *					
 *		   Outputs:- None
 *         
 * \return  Integer
 *          
 * \retval  0:- Senosor_Values array has a data to be vaildated.
 *          1:- Senosor_Values array do not have any data to be validated.
 ***************************************************************************************************
 */
int IsSensorInputBreached_Return_1(double* Senosor_Values)
{
 if ((Senosor_Values ==NULL_PTR)&& (Senosor_Values[0]==NULL))
 {
	return 1;
 }
 else 
 {
	 return 0;
 }
}

/**
 ***************************************************************************************************
 * Function Name: IsValidSensorInputwithinRange_Return_0
 * 
 * Function Description: check if the Sensor Inputs are not breached and not empty array.
 *
 * \param  Inputs:- double* Senosor_Values
 *					int NumOfValues
 *					double MaxDeltaValue
 *					
 *		   Outputs:- None
 *         
 * \return  Integer
 *          
 * \retval  0:- Jump in Sensor Readings is greater than threshold.
 *          1:- Jump in Sensor Reading is less than threshold and valid.
 ***************************************************************************************************
 */
int IsValidSensorInputwithinRange_Return_0(double* Senosor_Values, int NumOfValues, double MaxDeltaValue)
{
	int SensorArrayValueIndex=0;
	for( SensorArrayValueIndex=0; SensorArrayValueIndex< (NumOfValues-1); SensorArrayValueIndex++)
	{
		if(Senosor_Values[SensorArrayValueIndex+1] - Senosor_Values[SensorArrayValueIndex] < MaxDeltaValue) 
		{
			return 0;
		}
	}
	return 1;
}

/**
 ***************************************************************************************************
 * Function Name: Validate_Sensor_Readings
 * 
 * Function Description: Checks if the Sensor Readings are Validated against abrupt jumps and Validity of the Input reading.
 *
 * \param  Inputs:- double* Senosor_Values
 *					int NumOfValues
 *					double MaxDeltaValue
 *					
 *		   Outputs:- None
 *         
 * \return  Integer
 *          
 * \retval  0:- Senosor_Values is vaild.
 *          1:- Senosor_Values is not valid.
 ***************************************************************************************************
 */
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
	
	
	
	
	