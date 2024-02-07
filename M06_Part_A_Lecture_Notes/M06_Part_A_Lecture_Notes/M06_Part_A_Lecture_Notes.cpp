// M06_Part_A_Lecture_Notes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

// enum days { SUN = 15, MON, TUES, WED, THURS, FRI, SAT }; // declaration of enum

enum level { LOW = 1, MEDIUM, HIGH };

int main()
{
    /*
    for (int i = SUN; i <= SAT; i++)
    {
        cout << i << endl;
    }
    */
    level myVar = MEDIUM;

    // switch example
    switch (myVar)
    {
        case 1:
        {
            cout << "Low level" << endl;
            break;
        }
        case 2:
        {
            cout << "Medium level" << endl;
            break;
        }
        case 3:
        {
            cout << "High level" << endl;
            break;
        }
    }

    return 0;
}
