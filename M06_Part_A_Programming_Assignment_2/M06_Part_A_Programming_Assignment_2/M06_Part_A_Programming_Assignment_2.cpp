/* Program name: main.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 10/8/2023
*  Purpose: The program processes custom car orders for a car dealership using enums. The program can also enter more than one custom car order at a time.
*/

#include <iostream> // header file for cout and cin
#include <fstream> // header file for reading and writing to a file
#include <string> // header file for string data type
#include <algorithm> // header file for transform function

using namespace std; // use standard namespace for simplicity's sake

// enumerator declaration
enum carColorType { SUNSET, CHERRY, PHANTOM, TITANIUM, GEAUX, LIGHTNING, FOREST, MIDNIGHT, PASSION, ROOT, STORM, OCEAN, GLACIAL };

//function prototypes
carColorType getColor(string part);
string printColor(carColorType color);
void readExistingOrder();
void readExistingOrderOutput(string partName, int partColor);
void addNewOrder(string customerNames[], carColorType customerCarColors[][3], int numberOfOrders, bool& orderAccepted);
void quit(string customerNames[], carColorType customerCarColors[][3]);

int main()
{
    // declare variables
    int menuChoice, numberOfOrders = 0;
    string customerNames[10];
    carColorType customerCarColors[10][3];
    bool orderAccepted = false;
    // welcome user
    std::cout << "Welcome to the car customizer!" << endl;
    std::cout << endl;

    do
    {
        // intitalize first goto variable 
    jumping:

        // prompt user with menu
        std::cout << "Please choose an option from the menu:" << endl;
        std::cout << "1. Read Existing Order" << endl;
        std::cout << "2. Add New Order" << endl;
        std::cout << "3. Quit" << endl;
        cin >> menuChoice;

        //do input verification and checking
        if (!(cin))
        {
            cin.clear();
            cin.ignore(200, '\n');
            menuChoice = 0;
            std::cout << "You entered something that is not a number. Please Try again." << endl;
            continue;
        }
        else if (menuChoice < 1 || menuChoice > 3)
        {
            menuChoice = 0;
            continue;
        }

        // switch structure to handle the behavior of various menu options
        switch (menuChoice)
        {
        case 1:
        {

            readExistingOrder();
            goto jumping;
            break;

        }
        case 2:
        {


            addNewOrder(customerNames, customerCarColors, numberOfOrders, orderAccepted);
            if (orderAccepted == true && numberOfOrders < 9)
            {
                numberOfOrders++;
                goto jumping;
            }
            else if (numberOfOrders < 9)
            {
                goto jumping;
            }
            else
            {
                return 0;
            }
            break;


        }
        case 3:
        {
            quit(customerNames, customerCarColors);

            return 0;
        }
        }

    } while (menuChoice < 1 || menuChoice > 3);



    return 0;
}
// takes in a string and outputs an enumerator using a integer variable that has input validation
carColorType getColor(string part)
{
    //initialize variable 
    int partColorNum;

    // prompt user and accept input
    std::cout << "Please choose a color for the " << part << endl;
    std::cout << "1. Sunset Orange" << endl;
    std::cout << "2. Cherry Bomb" << endl;
    std::cout << "3. Phantom Black" << endl;
    std::cout << "4. Titanium Silver" << endl;
    std::cout << "5. Geaux Gold" << endl;
    std::cout << "6. Lightning Yellow" << endl;
    std::cout << "7. Forest Green" << endl;
    std::cout << "8. Midnight Blue" << endl;
    std::cout << "9. Passion Purple" << endl;
    std::cout << "10. Root Beer" << endl;
    std::cout << "11. Storm Surge" << endl;
    std::cout << "12. Ocean's Rip" << endl;
    std::cout << "13. Glacial White" << endl;
    cin >> partColorNum;

    // conditional structure within the iteration strucutre handles input failure, and too large or too small numbers
    do
    {
        if (!(cin))
        {
            cin.clear();
            cin.ignore(200, '\n');
            partColorNum = 0;
            std::cout << "You entered something that is not a number. Please Try again." << endl;
            std::cout << "Please enter the number next to the color you want to choose: ";
            cin >> partColorNum;
        }
        else if (partColorNum < 1 || partColorNum > 13)
        {
            std::cout << "Please enter the number next to the color you want to choose: ";
            cin >> partColorNum;
        }
        else
        {
            break;
        }

    } while (partColorNum < 1 || partColorNum > 13);

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
    return SUNSET;
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
    return "nothing";
}
void readExistingOrder()
{
    // declare variable
    string customerLastName;
    int topColor, bodyColor, trimColor;

    // prompt user to enter in customer last name
    std::cout << "Enter the customer last name for the order: ";
    cin >> customerLastName;
    std::cout << endl;

    // iterate the tolower function over the string so that string is lowercase
    transform(customerLastName.begin(), customerLastName.end(), customerLastName.begin(), ::tolower);

    // initalize ifstream variables
    ifstream readCustomCarOrder;

    // open file with customer's last name
    readCustomCarOrder.open(customerLastName + ".txt");

    // deal with file input failure
    if (!(readCustomCarOrder))
    {
        readCustomCarOrder.close();
        readCustomCarOrder.clear();
        std::cout << "The order for name could not be found or opened." << endl;
        std::cout << endl;

        return;
    }
    else
    {
        std::cout << "Here is the order for " << customerLastName << endl;
    }

    // read file data into int data type since it does not allow reading into enum data type
    readCustomCarOrder >> topColor;
    readCustomCarOrder >> bodyColor;
    readCustomCarOrder >> trimColor;

    //close file
    readCustomCarOrder.close();

    // call function to output color
    readExistingOrderOutput("Top", topColor);
    readExistingOrderOutput("Body", bodyColor);
    readExistingOrderOutput("Trim", trimColor);

    // add an additional line of blank space
    std::cout << endl;

    //end function
    return;
}
void readExistingOrderOutput(string partName, int partColor)
{
    // switch structure outputting top color
    switch (partColor)
    {
    case 0:
    {
        std::cout << partName << " Color: Sunset Orange" << endl;
        break;
    }
    case 1:
    {
        std::cout << partName << " Color: Cherry Bomb" << endl;
        break;
    }
    case 2:
    {
        std::cout << partName << " Color: Phantom Black" << endl;
        break;
    }
    case 3:
    {
        std::cout << partName << " Color: Titanium Silver" << endl;
        break;
    }
    case 4:
    {
        std::cout << partName << " Color: Geaux Gold" << endl;
        break;
    }
    case 5:
    {
        std::cout << partName << " Color: Lightning Yellow" << endl;
        break;
    }
    case 6:
    {
        std::cout << partName << " Color: Forest Green" << endl;
        break;
    }
    case 7:
    {
        std::cout << partName << " Color: Midnight Blue" << endl;
        break;
    }
    case 8:
    {
        std::cout << partName << " Color: Passion Purple" << endl;
        break;
    }
    case 9:
    {
        std::cout << partName << " Color: Root Beer" << endl;
        break;
    }
    case 10:
    {
        std::cout << partName << " Color: Storm Surge" << endl;
        break;
    }
    case 11:
    {
        std::cout << partName << " Color: Ocean's Rip" << endl;
        break;
    }
    case 12:
    {
        std::cout << partName << " Color: Glacial White" << endl;
        break;
    }
    }
    return;
}
// Adds a new order to the string array and the carColorType double array
void addNewOrder(string customerNames[], carColorType customerCarColors[][3], int numberOfOrders, bool& orderAccepted)
{
    // declare variables
    char continueWithOrder;



    // prompt user for customer name
    std::cout << "Enter the name for the order: ";
    cin >> customerNames[numberOfOrders];
    std::cout << endl;


    // get body, top, and trim colors from getColor function, body color is assigned at index 1, top color is assigned at index 1, and trim color is assigned at index 2
    customerCarColors[numberOfOrders][0] = getColor("body");
    customerCarColors[numberOfOrders][1] = getColor("top");
    customerCarColors[numberOfOrders][2] = getColor("trim");

    // display choices back to user
    std::cout << "You have chosen " << printColor(customerCarColors[numberOfOrders][0]) << " for the body, " << printColor(customerCarColors[numberOfOrders][1]) << " for the top, and " << printColor(customerCarColors[numberOfOrders][2]) << " for the trim." << endl;

    // prompt user if they want to continue with their order
    do
    {
        std::cout << "Do you want to continue with your order? ";
        cin >> continueWithOrder;
        continueWithOrder = toupper(continueWithOrder);

        switch (continueWithOrder)
        {
        case 'Y':
        {
            if (numberOfOrders < 9)
            {
                orderAccepted = true;
                return;
            }
            else
            {
                // initalize ofstream variable
                ofstream customCarOrders;

                // output customer names to file names
                for (int i = 0; i < 10; i++)
                {
                    // transform customer name to lowercase
                    transform(customerNames[i].begin(), customerNames[i].end(), customerNames[i].begin(), ::tolower);

                    // open file named customer name
                    customCarOrders.open(customerNames[i] + ".txt");

                    // input top, body, and trim colors into the file
                    customCarOrders << customerCarColors[i][1] << endl;
                    customCarOrders << customerCarColors[i][0] << endl;
                    customCarOrders << customerCarColors[i][2] << endl;

                    //close file
                    customCarOrders.close();
                }

                // prompt user that program is ending
                std::cout << "You have entered the maximum number of orders, the program will now save all orders and quit." << endl;
                std::cout << "Thank you for using the car customizer.The orders will be saved in files named customerLastName.txt." << endl;
                return;
            }

        }
        case 'N':
        {
            orderAccepted = false;
            customerNames[numberOfOrders] = " ";
            customerCarColors[numberOfOrders][0] = SUNSET;
            customerCarColors[numberOfOrders][1] = SUNSET;
            customerCarColors[numberOfOrders][2] = SUNSET;
            return;
        }
        default:
        {
            // clears input and prompts user for further input
            cin.clear();
            cin.ignore(200, '\n');
            std::cout << "Please enter Y or N." << endl;
            continue;
        }
        }
    } while (!(continueWithOrder == 'Y' || continueWithOrder == 'N'));
}
void quit(string customerNames[], carColorType customerCarColors[][3])
{
    // initalize ofstream variable
    ofstream customCarOrders;

    // output customer names to file names
    for (int i = 0; i < 10; i++)
    {
        // transform customer name to lowercase
        transform(customerNames[i].begin(), customerNames[i].end(), customerNames[i].begin(), ::tolower);

        // open file named customer name
        customCarOrders.open(customerNames[i] + ".txt");

        // input top, body, and trim colors into the file
        customCarOrders << customerCarColors[i][1] << endl;
        customCarOrders << customerCarColors[i][0] << endl;
        customCarOrders << customerCarColors[i][2] << endl;

        //close file
        customCarOrders.close();
    }

    std::cout << "Thank you for using the car customizer.The orders will be saved in files named customerLastName.txt." << endl;

    return;
}
