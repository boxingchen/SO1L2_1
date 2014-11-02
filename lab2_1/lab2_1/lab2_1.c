/* File: lab2_1.c */
/* Alexander Ustyuzhanin, IE SO1 group 1, WS14, 13.10.2014 */

/* Test case 1
Values entered:	10, 5, 7.5, 15
Min temp = 5
Max temp = 15
Mean value: (10 + 5 + 7.5 + 15)/4 = 37.5/4 = 9.375
Standard deviation: sqrt((100 + 25 + 56.25 + 225 - 4*87.890625)/(4-1)) = sqrt(54.6875/3) = sqrt(18.23) = 4,27

Program output:
============================== Lab 2 Assignment 1 ==============================

Enter the sequence of temperature values line by line
When done enter any character and press enter
10
Read 1 temperature value
Minimum temperature is 10.000
Maximum temperature is 10.000
Mean temperature is 10.000
5
Read 2 temperature values
Minimum temperature is 5.000
Maximum temperature is 10.000
Mean temperature is 7.500
Standard temperaure deviation is 3.536
7.5
Read 3 temperature values
Minimum temperature is 5.000
Maximum temperature is 10.000
Mean temperature is 7.500
Standard temperaure deviation is 2.500
15
Read 4 temperature values
Minimum temperature is 5.000
Maximum temperature is 15.000
Mean temperature is 9.375
Standard temperaure deviation is 4.270
c
End of input

Press any key to continue . . .
*/

/* Test case 2
Values entered:	-1 -5 6 0 -1 1
Min temp = -5
Max temp = 6
Mean value: (-1 + -5 + 6 + 0 + -1 + 1)/6 = 0/6 = 0
Standard deviation: sqrt((1 + 25 + 36 + 0 + 1 + 1 - 6*0)/(6-1)) = sqrt(64/5) = sqrt(12.8) = 3.578

Program output:
============================== Lab 2 Assignment 1 ==============================

Enter the sequence of temperature values line by line
When done enter any character and press enter
-1
Read 1 temperature value
Minimum temperature is -1.000
Maximum temperature is -1.000
Mean temperature is -1.000
-5
Read 2 temperature values
Minimum temperature is -5.000
Maximum temperature is -1.000
Mean temperature is -3.000
Standard temperaure deviation is 2.828
6
Read 3 temperature values
Minimum temperature is -5.000
Maximum temperature is 6.000
Mean temperature is 0.000
Standard temperaure deviation is 5.568
0
Read 4 temperature values
Minimum temperature is -5.000
Maximum temperature is 6.000
Mean temperature is 0.000
Standard temperaure deviation is 4.546
-1
Read 5 temperature values
Minimum temperature is -5.000
Maximum temperature is 6.000
Mean temperature is -0.200
Standard temperaure deviation is 3.962
1
Read 6 temperature values
Minimum temperature is -5.000
Maximum temperature is 6.000
Mean temperature is 0.000
Standard temperaure deviation is 3.578
c
End of input

Press any key to continue . . .
*/

#define _CRT_SECURE_NO_WARNINGS										// suppress warnings about unsafe scanf (C4996)
#include <stdio.h>													// for the IO functions
#include <stdlib.h>													// for system("pause")
#include <math.h>													// for mathematical functions, e.g. pow() and sqrt()

int main()
{
	char isNumber			= 1;									// determines the exit condition of the cycle
	unsigned int count		= 0;									// stores the number of temperature values that have been entered
	float currentTemp		= 0.0;									// stores the temperature value that is currently being processed
	float sumTemp			= 0.0;									// stores the sum of all temperature values (needed to calculate other values)
	float sqSumTemp			= 0.0;									// stores the sum of all squared temperature values (needed to calculate other values)
	float maxTemp			= 0.0;									// stores the maximum temperature
	float minTemp			= 0.0;									// stores the minimum temperature
	float meanTemp			= 0.0;									// stores the mean temperature (calculated)
	float stdTempDeviation	= 0.0;									// stores the stamdard temperature deviation (calculated)
	float sqDeviation		= 0.0;
	printf("============================== Lab 2 Assignment 1 ==============================\n");
	printf("Enter the sequence of temperature values line by line\nWhen done enter any character and press enter\n");
	do																// the cycle that reads the values from the user
	{
		if((scanf("%f", &currentTemp)) == 1)						// this checks whether the user entered a number or a character. The scanf expects to read a floating point number (the format string is "%f"). If it reads EOF it will return -1
		{															// if it reads anything that can't interpreted as a floating point number, it will return 0. In case it reads a floating point number successfully it will return 1 (in this case, since it has successfully read one value)		
			if(count == 0)											// if this is the first time passing through the cycle (first temperature value), we need to write the temperature value both to min and max variables
				maxTemp = minTemp = currentTemp;
			count++;												// increase the total number of temperature values entered counter
			sumTemp += currentTemp;									// add this temperature value to the sum of all temperature values
			sqSumTemp += (float) pow(currentTemp,2);				// do the same for squared sum
			if(currentTemp > maxTemp)								// these two statements check if the currently processed temperature is higher than currently stored max temperature
				maxTemp = currentTemp;								// or lower than currently stored min temperature and update one of the values accordingly
			if(currentTemp < minTemp)
				minTemp = currentTemp;
			if(count > 1)											// if there were at least 2 values entered, it makes sense to calculate everything
			{
				meanTemp = sumTemp/count;							// calculate the mean temperature
				sqDeviation = (float) (sqSumTemp - count*pow(meanTemp,2))/(count - 1);
				if(sqDeviation >= 0)								// check because the float error accumulates and may cause negative value as a result of this equation
					stdTempDeviation = (float) sqrt(sqDeviation);	// calculate the standard temperature deviation
				printf("Read %d temperature values\n", count);		// display the results
				printf("Minimum temperature is %.3f\n", minTemp);
				printf("Maximum temperature is %.3f\n", maxTemp);
				printf("Mean temperature is %.3f\n", meanTemp);
				printf("Standard temperaure deviation is %.3f\n", stdTempDeviation);
			}
			else
			{
				meanTemp = currentTemp;

				printf("Read %d temperature value\n", count);		// display the results
				printf("Minimum temperature is %.3f\n", minTemp);
				printf("Maximum temperature is %.3f\n", maxTemp);
				printf("Mean temperature is %.3f\n", meanTemp);
			}
		}
		else														// once we're done reading the values, we can start calculating and displaying the results
		{
			printf("End of input\n\n");
			isNumber = 0;											// if the user enters a symbol instead of a number - set the cycle exit condition
		}
	}
	while(isNumber);												// the cycle is terminated when user enters a character instead of a number

	system("pause");												// let the user see the results
	return 0;														// the return value for int main()
}