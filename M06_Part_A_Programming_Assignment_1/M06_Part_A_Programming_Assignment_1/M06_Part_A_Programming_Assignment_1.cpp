/* Program name: main.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 10/4/2023
*  Purpose: The program processes custom car orders for a car dealership using enums.
*/

#include <iostream> // header file for cout and cin
#include <fstream> // header file for ofstream
#include <string> // header file for string data type

using namespace std; // use standard namespace for simplicity's sake

// enumerator declaration
enum carColorType {SUNSET = 1, CHERRY, PHANTOM, TITANIUM, GEAUX, LIGHTNING, FOREST, MIDNIGHT, PASSION, ROOT, STORM, OCEAN, GLACIAL};

//function prototypes
carColorType getColor(string part);
string printColor(carColorType color);

int main()
{
    // declare enumerator variables 
    carColorType bodyColor, topColor, trimColor;
    char continueWithOrder;


    // get body, top, and trim colors from getColor function
    bodyColor = getColor("body");
    topColor = getColor("top");
    trimColor = getColor("trim");
    
    // display choices back to user
    cout << "You have chosen " << printColor(bodyColor) << " for the body, " << printColor(topColor) << " for the top, and " << printColor(trimColor) << " for the trim." << endl;

    // prompt user if they want to continue with their order
    do
    {
        cout << "Do you want to continue with your order? ";
        cin >> continueWithOrder;
        continueWithOrder = toupper(continueWithOrder);

        switch (continueWithOrder)
        {
            case 'Y':
            {
                // set up variable to output data to file
                ofstream customCarOrder;

                // open file 
                customCarOrder.open("order.txt");

                // input values into the file
                customCarOrder << topColor << endl;
                customCarOrder << bodyColor << endl;
                customCarOrder << trimColor << endl;

                // close file
                customCarOrder.close();

                return 0;

            }
            case 'N':
            {
                // exits program
                return 0;
            }
            default:
            {
                // clears input and prompts user for further input
                cin.clear();
                cin.ignore(200, '\n');
                cout << "Please enter Y or N." << endl;
                continue;
            }
        }
    } 
    while (!(continueWithOrder == 'Y' || continueWithOrder == 'N'));

    return 0;
}
// takes in a string and outputs an enumerator using a integer variable that has input validation
carColorType getColor(string part)
{
    //initialize variable 
    int partColorNum;

    // prompt user and accept input
    cout << "Welcome to the car customizer!" << endl;
    cout << "Please choose a color for the " << part << endl;
    cout << "1. Sunset Orange" << endl;
    cout << "2. Cherry Bomb" << endl;
    cout << "3. Phantom Black" << endl;
    cout << "4. Titanium Silver" << endl;
    cout << "5. Geaux Gold" << endl;
    cout << "6. Lightning Yellow" << endl;
    cout << "7. Forest Green" << endl;
    cout << "8. Midnight Blue" << endl;
    cout << "9. Passion Purple" << endl;
    cout << "10. Root Beer" << endl; 
    cout << "11. Storm Surge" << endl;
    cout << "12. Ocean's Rip" << endl;
    cout << "13. Glacial White" << endl;
    cin >> partColorNum;

    // conditional structure within the iteration strucutre handles input failure, and too large or too small numbers
    do
    {
        if (!(cin))
        {
            cin.clear();
            cin.ignore(200, '\n');
            partColorNum = 0;
            cout << "You entered something that is not a number. Please Try again." << endl;
            cout << "Please enter the number next to the color you want to choose: ";
            cin >> partColorNum;
        }
        else if (partColorNum < 1 || partColorNum > 13)
        {
            cout << "Please enter the number next to the color you want to choose: ";
            cin >> partColorNum;
        }
        else
        {  
            break;
        }
        
    } 
    while (partColorNum < 1 || partColorNum > 13);

    // input int numbers, output enum values
    switch (partColorNum)
    {
        case 1:
        {
            return SUNSET;
        }
        case 2:
        {
            return CHERRY;
        }
        case 3:
        {
            return PHANTOM;
        }
        case 4:
        {
            return TITANIUM;
        }
        case 5:
        {
            return GEAUX;
        }
        case 6:
        {
            return LIGHTNING;
        }
        case 7:
        {
            return FOREST;
        }
        case 8:
        {
            return MIDNIGHT;
        }
        case 9:
        {
            return PASSION;
        }
        case 10:
        {
            return ROOT;
        }
        case 11:
        {
            return STORM;
        }
        case 12:
        {
            return OCEAN;
        }
        case 13:
        {
            return GLACIAL;
        }
    }
}
//takes a enumerator variable and outputs a string representing it's name
string printColor(carColorType color)
{
    switch (color)
    {
        case SUNSET:
        {
            return "Sunset Orange";
        }
        case CHERRY:
        {
            return "Cherry Bomb";
        }
        case PHANTOM:
        {
            return "Phantom Black";
        }
        case TITANIUM:
        {
            return "Titanium Silver";
        }
        case GEAUX:
        {
            return "Geaux Gold";
        }
        case LIGHTNING:
        {
            return "Lightning Yellow";
        }
        case FOREST:
        {
            return "Forest Green";
        }
        case MIDNIGHT:
        {
            return "Midnight Blue";
        }
        case PASSION:
        {
            return "Passion Purple";
        }
        case ROOT:
        {
            return "Root Beer";
        }
        case STORM:
        {
            return "Storm Surge";
        }
        case OCEAN:
        {
            return "Ocean's Rip";
        }
        case GLACIAL:
        {
            return "Glacial White";
        }
    }
}