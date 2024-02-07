/* Program name: main.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 9/26/2023
*  Purpose: Calculate speed due to acceleration from button press for a game and output a table.
*/

// header files 
#include <iostream> // header file for cout and cin
#include <iomanip> // header file for setw and setfill

using namespace std; // use standard namespace for simplicity's sake

// function prototypes
double speedDueToAcceleration(double acceleration, int time);
double accelerationFromButton(double buttonForce);

int main()
{
    // to keep them easier to track, the main() local variables are named the same as in the local functions
    double buttonForce;
    int time;

    // user is prompted to enter the button force between 0 and 10 in a loop, which is checked for input failure and button force being less than 0 or greater than 10
    do
    {
        cout << "Enter the button force between 0 and 10:" << endl;
        cin >> buttonForce;

        if (!(cin))
        {
            cout << "You entered something that is not a number. Please Try again." << endl;
            cin.clear();
            cin.ignore(200, '\n');
            buttonForce = -1; // buttonForce needs a value to avoid exiting out of the loop
            continue;
        }
        else if (buttonForce < 0 || buttonForce > 10)
        {
            cout << "The button force needs to be between 0 and 10." << endl;
            continue;
        }
        else
        {
            break;
        }
    } while (buttonForce < 0 || buttonForce > 10);

    // user is prompted to enter the time greater than 0 in a loop, which is checked for input failure and time being less or equal to zero
    do
    {
        cout << "Enter the total acceleration time in seconds:" << endl;
        cin >> time;

        if (!(cin))
        {
            cout << "You entered something that is not a number. Please Try again." << endl;
            cin.clear();
            cin.ignore(200, '\n');
            time = -1; // time needs a value to avoid exiting out of the loop
            continue;
        }
        else if (time <= 0)
        {
            cout << "The total acceleration time must be greater than 0." << endl;
            continue;
        }
        else
        {
            break;
        }
    } while (time <= 0);


    // output for acceleration and heading of table 
    // don't forget to format to 3 decimal places
    cout << "Acceleration is " << fixed << showpoint << setprecision(3) << accelerationFromButton(buttonForce) << " m/s^2" << endl;
    cout << "Time in s" << setw(15) << "Speed in m/s" << endl;
    cout << setw(30) << setfill('*') << "*" << endl;
    cout << setfill(' ');

    // declare iteration variable as an integer, then use if else structure and for loops to output table
    int i = 0;

    if (time % 3 == 0)
    {
        for (i = 0; i <= time; i += 3)
        {
            cout << i << setw(15) << fixed << showpoint << setprecision(3) << speedDueToAcceleration(accelerationFromButton(buttonForce), i) << endl;
        }
    }
    else
    {
        for (i = 0; i < time; i += 3)
        {
            cout << i << setw(15) << fixed << showpoint << setprecision(3) << speedDueToAcceleration(accelerationFromButton(buttonForce), i) << endl;
        }
        cout << time << setw(15) << fixed << showpoint << setprecision(3) << speedDueToAcceleration(accelerationFromButton(buttonForce), time) << endl;
    }
    return 0;
}

// function definitions
double speedDueToAcceleration(double acceleration, int time)
{
    return acceleration * time;
}
double accelerationFromButton(double buttonForce)
{
    return buttonForce * 0.463;
}
