/* Program name: main.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 9/17/2023
*  Purpose: The program will convert binary numbers of unlimited size into their equivalent decimal numbers using a do while loop.
*/

#include <iostream> // for cin and cout
#include <string> // for string data type
#include <cmath> // for usage of the power function

using namespace std; // use standard namespace for simplicity's sake

int main() // main function we put all the code in
{
    // initialize variables
    int binaryDigit = 0, decimalNumber = 0, numberOfBinaryDigits = 1;
    string numberOfBinaryDigitsEnding;

    // description of what the program does
    cout << "Welcome to the binary number converter 2.0." << endl;
    cout << "You will enter a binary number 1 digit at a time starting at the right and the program will convert the number to decimal." << endl;

    // main loop
    do
    {
        // switch structure to handle the ending of the number of binary digits in the prompt
        switch (numberOfBinaryDigits)
        {
        case 1:
            numberOfBinaryDigitsEnding = "st";
            break;

        case 2:
            numberOfBinaryDigitsEnding = "nd";
            break;

        case 3:
            numberOfBinaryDigitsEnding = "rd";
            break;

        default:
            numberOfBinaryDigitsEnding = "th";
        }

        // Prompt user to enter binary digits with -1 as a sentinel value
        cout << "Enter the " << numberOfBinaryDigits << numberOfBinaryDigitsEnding << " binary digit (Enter -1 to complete the conversion): " << endl;
        cin >> binaryDigit;

        // if structure to handle input error, the number not being a 0 or 1, the number being a -1, and the formula to follow if the binary number is valid
        if (!(cin))
        {
            cout << "You entered something that is not a number." << endl;
            cin.clear();
            cin.ignore(200, '\n');
            continue;
        }
        else if (binaryDigit == -1)
        {
            break;
        }
        else if (!(binaryDigit == 0 || binaryDigit == 1))
        {
            cout << "A binary digit can only be a 1 or 0." << endl;
            continue;
        }
        else
        {
            decimalNumber += (binaryDigit * pow(2, (numberOfBinaryDigits - 1)));
        }

        // increase number of binary digit counter by 1
        numberOfBinaryDigits++;

    } while (!(binaryDigit == -1));

    // output number in decimal notation
    cout << "Your number in decimal is " << decimalNumber << endl;

    return 0;
}