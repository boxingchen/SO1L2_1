/* File: lab2_1.c */
/* Alexander Ustyuzhanin, IE SO1 group 1, WS14, 13.10.2014 */

#define _CRT_SECURE_NO_WARNINGS							// suppress warnings about unsafe scanf (C4996)
#include <stdio.h>										// for the IO functions
#include <stdlib.h>										// for system("pause")
#include <math.h>										// for mathematical functions, e.g. pow() and sqrt()

int main()
{
	char isNumber			= 1;						// determines the exit condition of the cycle
	int count				= 0;						// stores the number of temperature values that have been entered
	float currentTemp		= 0.0;						// stores the temperature value that is currently being processed
	float sumTemp			= 0.0;						// stores the sum of all temperature values (needed to calculate other values)
	float sqSumTemp			= 0.0;						// stores the sum of all squared temperature values (needed to calculate other values)
	float maxTemp			= 0.0;						// stores the maximum temperature
	float minTemp			= 0.0;						// stores the minimum temperature
	float meanTemp			= 0.0;						// stores the mean temperature (calculated)
	float stdTempDeviation	= 0.0;						// stores the stamdard temperature deviation (calculated)
	
	printf("============================== Lab 2 Assignment 1 ==============================\n");
	printf("Enter the sequence of temperature values line by line\nWhen done enter any character and press enter\n");
	do													// the cycle that reads the values from the user
	{
		if((scanf("%f", &currentTemp)) == 1)			// this checks whether the user entered a number or a character. The scanf expects to read a floating point number (the format string is "%f"). If it reads EOF it will return -1
		{												// if it reads anything that can't interpreted as a floating point number, it will return 0. In case it reads a floating point number successfully it will return 1 (in this case, since it has successfully read one value)		
			if(count == 0)								// if this is the first time passing through the cycle (first temperature value), we need to write the temperature value both to min and max variables
				maxTemp = minTemp = currentTemp;
			count++;									// increase the total number of temperature values entered counter
			sumTemp += currentTemp;						// add this temperature value to the sum of all temperature values
			sqSumTemp += pow(currentTemp,2);			// do the same for squared sum
			if(currentTemp > maxTemp)					// these two statements check if the currently processed temperature is higher than currently stored max temperature
				maxTemp = currentTemp;					// or lower than currently stored min temperature and update one of the values accordingly
			if(currentTemp < minTemp)
				minTemp = currentTemp;
			meanTemp = sumTemp/count;					// calculate the mean temperature			
			stdTempDeviation = sqrt((sqSumTemp - count*(pow(meanTemp,2)))/(count - 1));	// calculate the standard temperature deviation
		}
		else
		{
			isNumber = 0;								// if the user enters a symbol instead of a number - set the cycle exit condition
			printf("End of input\n\n");					
		}
	}
	while(isNumber);									// the cycle is terminated when user enters a character instead of a number

	printf("Read %d temperature values\n", count);		// display the results
	printf("Minimum temperature is %f\n", minTemp);
	printf("Maximum temperature is %f\n", maxTemp);
	printf("Mean temperature is %f\n", meanTemp);
	printf("Standard temperaure deviation is %f\n", stdTempDeviation);

	system("pause");									// let the user see the results
	return 0;											// the return value for int main()
}