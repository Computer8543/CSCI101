/* Program name: M05_Part_A_Lecture_Lab_Activity.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 9/25/2023
*  Purpose: Add, subtract, multiply, and divide two numbers using functions for each operation.
*/

#include <iostream> // header file for cin and cout
#include <cassert> // header file for assert function 

using namespace std; // use standard namespace for simplicity's sake

// function prototypes
float addition(float x, float y);
float subtraction(float x, float y);
float multiplication(float x, float y);
float division(float x, float y);

int main()
{
    // declare variables
    float firstNumber, secondNumber;
    int menuChoice;

    // prompt the user to enter first number
    cout << "Enter first number " << endl;
    cin >> firstNumber;

    // check for input failure for the first number:
    if (!cin)
        return 1;

    // prompt the user to enter second number
    cout << "Enter second number " << endl;
    cin >> secondNumber;
    
    // check for input failure for the second number:
    if (!cin)
        return 1;

    // prompt the user to choose to add, subtract, multiply, or divide the two numbers
    cout << "Which operation do you want to do with the two numbers?" << endl;
    cout << "1: Addition" << endl;
    cout << "2: Subtraction" << endl;
    cout << "3: Multiplication" << endl;
    cout << "4: Division" << endl;
    cin >> menuChoice;

    // switch structure to call functions according to menu choice
    switch (menuChoice)
    {
        case 1: 
        {
            cout << "The sum is " << addition(firstNumber, secondNumber) << "." << endl;
            break;
        }

        case 2:
        {
            cout << "The difference is " << subtraction(firstNumber, secondNumber) << "." << endl;
            break;
        }

        case 3:
        {
            cout << "The product is " << multiplication(firstNumber, secondNumber) << "." << endl;
            break;
        }

        case 4:
        {
            cout << "The quotient is " << division(firstNumber, secondNumber) << "." << endl;
            break;
        }

        default:
            cout << "Invalid input" << endl; 
            return 2;
    }
    
    
    // exit program normally
    return 0;
}

// function definitions
float addition(float x, float y)
{
    return x + y;
}

float subtraction(float x, float y)
{
    return x - y;
}

float multiplication(float x, float y)
{
    return x * y;
}

// divide bigger number by smaller number, and halt program if the smaller variable is zero
float division(float x, float y)
{
    if (x > y)
        {
            assert(y != 0);
            return x / y;
        }
    else
        {
            assert(x != 0);
            return y / x;
        }
}       

