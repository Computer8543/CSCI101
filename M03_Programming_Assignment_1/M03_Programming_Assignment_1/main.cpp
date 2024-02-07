/* Program name: main.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 9/9/2023
*  Purpose: Prompt the user to determine if they have enough RAM in gigabytes to perform one of a list/menu of tasks within the console.
*			Check both inputs to see if they have input failure and if they satisfy the correct conditions for the input.
*			If input failure is detected or if they don't satsify the correct conditions for the input, display an error message
*			and exit early.
*/

#include <iostream> // allows for using cout and cin

using namespace std; //initialize standard namespace for simplicity's sake

int main() // initialize main function
{
	// variable initialization
	int RAM_Amount, input_Menu_Number;

	// constant initialization 
	const int menu_RAM_Number1 = 12;
	const int menu_RAM_Number2 = 8;
	const int menu_RAM_Number3 = 16;
	const int menu_RAM_Number4 = 8;
	const int menu_RAM_Number5 = 20;
	const int menu_RAM_Number6 = 8;
	const int menu_RAM_Number7 = 6;
	const int menu_RAM_Number8 = 6;
	const int menu_RAM_Number9 = 32;

	// Prompt the user to enter the amount of RAM in GB,
	cout << "Enter the amount of RAM in GB " << endl;
	cin >> RAM_Amount;

	// check the input for input failure and to see if the input is greater than or equal to zero
	if (!(cin) || RAM_Amount <= 0)
	{
		cout << "You have entered an invalid value. The program will be unable to continue. Exiting." << endl;
		return 1;
	}



	// prompt user with menu using strings, and then recieve user input
	cout << "Choose the task you want to do on your computer from the following list:" << endl;
	cout << "1. Android Studio" << endl;
	cout << "2. Visual Studio Code" << endl;
	cout << "3. Gaming" << endl;
	cout << "4. Web Browsing with Chrome" << endl;
	cout << "5. Multiple Programming Tasks (both Android Studio and Visual Studio Code)" << endl;
	cout << "6. Zoom" << endl;
	cout << "7. Email" << endl;
	cout << "8. Create and edit documents" << endl;
	cout << "9. Everything listed above" << endl;
	cin >> input_Menu_Number;


	// check the input for input failure and to see if the input is at or between 1 and 9
	if (!(cin) || (!(1 <= input_Menu_Number <= 9)))
	{
		cout << "You have entered an invalid value. The program will be unable to continue. Exiting." << endl;
		return 2;
	}

	// responses for user choices from menu 
	switch (input_Menu_Number)
	{
	case 1:
		if (RAM_Amount >= menu_RAM_Number1)
		{
			cout << "Congratulations! You have sufficient RAM for your task." << endl;
			break;
		}
		else
		{
			cout << "Sorry the RAM you have is not sufficient." << endl;
			break;
		}
	case 2:
		if (RAM_Amount >= menu_RAM_Number2)
		{
			cout << "Congratulations! You have sufficient RAM for your task." << endl;
			break;
		}
		else
		{
			cout << "Sorry the RAM you have is not sufficient." << endl;
			break;
		}
	case 3:
		if (RAM_Amount >= menu_RAM_Number3)
		{
			cout << "Congratulations! You have sufficient RAM for your task." << endl;
			break;
		}
		else
		{
			cout << "Sorry the RAM you have is not sufficient." << endl;
			break;
		}
	case 4:
		if (RAM_Amount >= menu_RAM_Number4)
		{
			cout << "Congratulations! You have sufficient RAM for your task." << endl;
			break;
		}
		else
		{
			cout << "Sorry the RAM you have is not sufficient." << endl;
			break;
		}
	case 5:
		if (RAM_Amount >= menu_RAM_Number5)
		{
			cout << "Congratulations! You have sufficient RAM for your task." << endl;
			break;
		}
		else
		{
			cout << "Sorry the RAM you have is not sufficient." << endl;
			break;
		}
	case 6:
		if (RAM_Amount >= menu_RAM_Number6)
		{
			cout << "Congratulations! You have sufficient RAM for your task." << endl;
			break;
		}
		else
		{
			cout << "Sorry the RAM you have is not sufficient." << endl;
			break;
		}
	case 7:
		if (RAM_Amount >= menu_RAM_Number7)
		{
			cout << "Congratulations! You have sufficient RAM for your task." << endl;
			break;
		}
		else
		{
			cout << "Sorry the RAM you have is not sufficient." << endl;
			break;
		}
	case 8:
		if (RAM_Amount >= menu_RAM_Number8)
		{
			cout << "Congratulations! You have sufficient RAM for your task." << endl;
			break;
		}
		else
		{
			cout << "Sorry the RAM you have is not sufficient." << endl;
			break;
		}
	case 9:
		if (RAM_Amount >= menu_RAM_Number9)
		{
			cout << "Congratulations! You have sufficient RAM for your task." << endl;
			break;
		}
		else
		{
			cout << "Sorry the RAM you have is not sufficient." << endl;
			break;
		}
	default:
		cout << "You have entered an invalid value. The program will be unable to continue. Exiting." << endl;

	}
	return 0;
}