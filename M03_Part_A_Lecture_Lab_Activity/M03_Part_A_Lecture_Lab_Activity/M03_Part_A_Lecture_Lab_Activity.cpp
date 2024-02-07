/* Program name: M03_Part_A_Lecture_Lab_Activity
*  Author: Kyle Ingersoll
*  Date last updated: 9/6/2023
*  Purpose: Assuming that the baby alarm is on, check to see if the baby is crying or if the temperature is below 70 degrees Fahrenheit.
*			If either of those conditions are true, output that "The alarm will go off". 
*/

#include <iostream>

using namespace std;

int main()
{
	// setting up variables 
	bool alarmState = true; // true = alarm is on and false = alarm is off
	bool babyCry; // true = baby is crying, false = baby is not crying
	int temperature;

	// user prompt 
	cout << "Enter temperature in Fahrenheit: " << endl;
	cin >> temperature;
	cout << "Enter if the baby is crying, true or false: " << endl;
	cin >> babyCry;

	// checking if the baby is crying or if temperature is below 70
	if (babyCry == true || temperature < 70)
		cout << "The alarm will go off" << endl;
	else
		cout << "The alarm stays silent" << endl;

	return 0; 

}

