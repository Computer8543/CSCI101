/* Program name: main.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 10/10/2023
*  Purpose: The program allows the user to enter an order for a mold and create an invoice in the form of an output file, while using the struct data type.
*/

#include <iostream> // header file for cout and cin
#include <string> // header file for string data type
#include <fstream> // header file for file input and output
#include <iomanip> // header file for setprecision() function

using namespace std; // using standard namespace for simplicity's sake

// declare size enumeration
enum sizeType {S, M, L};

// declare structs

// declare mold struct
struct moldType {
    string shape;
    sizeType size;
    double price, weight;
};

// declare customer struct
struct customerType {
    string fname, lname, address, cityStateAndZipCode;
};

// declare order struct
struct orderType {
    customerType customer;
    moldType products[10];
    int numProdOrdered = 0;
    double subTotal, totalWeight, shippingCost;
};

// declare function prototypes
void readCatalog(moldType productCatalog[], int numProducts);
void enterOrder(orderType& order, moldType catalog[], int numItemsInCatalog);
void printProduct(ostream&, moldType mold);
void printOrder(ostream&, orderType&);

int main()
{
    // declare variables and constants
    moldType currentProductCatalog[20];
    int numberOfProductsInCatalog = 20;
    orderType order;
    ofstream printTheOrder;
    char enterAnotherOrderChoice;

    // welcome user to the program
    cout << "Welcome to Judy's Resin Molds!" << endl;

    // populate array with catalog.txt data
    readCatalog(currentProductCatalog, numberOfProductsInCatalog);

    do
    {
        // enter order into system
        enterOrder(order, currentProductCatalog, numberOfProductsInCatalog);

        // output order into console
        printOrder(cout, order);

        // open file
        printTheOrder.open(order.customer.lname + ".txt");

        // print to file
        printOrder(printTheOrder, order);

        // close file
        printTheOrder.close();

        // prompt user if they want to enter another order
        cout << "Do you want to enter another order?";
        cin >> enterAnotherOrderChoice;
        cout << endl;
        do
        {
            enterAnotherOrderChoice = tolower(enterAnotherOrderChoice);

            switch (enterAnotherOrderChoice)
            {
            case 'y':
            {
                continue;
            }
            case 'n':
            {
                break;
            }
            default:
            {
                cout << "That is not a valid entry.  Please enter y or n." << endl;
                continue;
            }
            }
        } while (!(enterAnotherOrderChoice == 'y' || enterAnotherOrderChoice == 'n'));
    } while (!(enterAnotherOrderChoice == 'n'));

    return 0;
}
// reads catalog.txt to get information about the molds for sale.
void readCatalog(moldType productCatalog[], int numProducts)
{
    // declare variables
    ifstream readCatalog;
    char productSize[20];
    int i;

    // open file
    readCatalog.open("catalog.txt");

    // deal with ifstream input failure
    if (!(readCatalog))
    {
        readCatalog.close();
        cout << "Data invalid, Please Try again" << endl;
    }

    // populate productCatalog array with information from the file
    for (i = 0; i < numProducts; i++)
    {
        readCatalog >> productCatalog[i].shape;
        readCatalog >> productSize[i];
        readCatalog >> productCatalog[i].price;
        readCatalog >> productCatalog[i].weight;
    }

    // close file
    readCatalog.close();

    // populate productCatalog array member size with a switch structure within a for array
    for (i = 0; i < numProducts; i++)
    {
        switch (productSize[i])
        {
            case 'S':
            {
                productCatalog[i].size = S;
                continue;
            }
            case 'M':
            {
                productCatalog[i].size = M;
                continue;
            }
            case 'L':
            {
                productCatalog[i].size = L;
                continue;
            }
            default:
            {
                cout << "Invalid data within file." << endl;
                break;
            }

        }
    }
    return;
}

// prompts the user to enter order information and allows the user to select up to 10 items.
void enterOrder(orderType& order, moldType catalog[], int numItemsInCatalog)
{
    // declare variables
    int i, productChoice = 0;
    char addAnotherProductToTheOrderChoice;

    // prompt user for first and last name, street address, city, state, and zipcode
    cout << "Enter the customer first name: ";
    cin >> order.customer.fname;
    cout << endl;
    cout << "Enter the customer last name: ";
    cin >> order.customer.lname;
    cout << endl;
    cin.clear(); // code was skipping past the "Enter the customer street address: " part
    cin.ignore(200, '\n');
    cout << "Enter the customer street address: ";
    getline(cin, order.customer.address);
    cout << endl;
    cout << "Enter the customer city, state, and zip code: ";
    getline(cin, order.customer.cityStateAndZipCode);
    cout << endl;

    do
    {
        // prompt user to please choose product from list
        cout << "Please choose a product from list:" << endl;

        // for loop that outputs each line of the catalog
        for (i = 0; i < numItemsInCatalog; i++)
        {
            cout << i + 1 << ". " << catalog[i].shape << " - ";
            if (catalog[i].size == S)
            {
                cout << "Small ";
            }
            else if (catalog[i].size == M)
            {
                cout << "Medium ";
            }
            else if (catalog[i].size == L)
            {
                cout << "Large ";
            }
            else
            {
                cout << "Error ";
            }
            cout << "$" << catalog[i].price << " " << fixed << showpoint << setprecision(2) << catalog[i].weight << "g" << endl;
        }
        // do while loop that repeats input until conditions are satisfied
        do
        {
            cin >> productChoice;

            if (!(cin))
            {
                cin.clear();
                cin.ignore(200, '\n');
                productChoice = 0;
                cout << "You entered something that is not a number. Please Try again." << endl;
                continue;
            }
            else if (productChoice < 1 || productChoice > numItemsInCatalog)
            {
                cout << "That is not a valid choice. Please choose a product from the list above." << endl;
                continue;
            }
            else
            {
                continue;
            }
        } while (productChoice < 1 || productChoice > numItemsInCatalog);

        // assignment statements for the members of order
        order.products[order.numProdOrdered].shape = catalog[(productChoice - 1)].shape;
        order.products[order.numProdOrdered].size = catalog[(productChoice - 1)].size;
        order.products[order.numProdOrdered].price = catalog[(productChoice - 1)].price;
        order.products[order.numProdOrdered].weight = catalog[(productChoice - 1)].weight;
        

        // output item ordered
        cout << "Item: " << order.products[order.numProdOrdered].shape << " - ";
        if (order.products[order.numProdOrdered].size == S)
        {
            cout << "Small ";
        }
        else if (order.products[order.numProdOrdered].size == M)
        {
            cout << "Medium ";
        }
        else if (order.products[order.numProdOrdered].size == L)
        {
            cout << "Large ";
        }
        else
        {
            cout << "Error ";
        }
        cout << "$" << order.products[order.numProdOrdered].price << " " << fixed << showpoint << setprecision(2) << order.products[order.numProdOrdered].weight << "g  added." << endl;

        // make numProdOrdered go up by 1
        order.numProdOrdered++;

        // prompt user if they want to add another product to the order, and deal with not allowed choices
        do
        {
            cout << "Do you want to add another product to the order?";
            cin >> addAnotherProductToTheOrderChoice;
            cout << endl;
            addAnotherProductToTheOrderChoice = tolower(addAnotherProductToTheOrderChoice);

            if (!(addAnotherProductToTheOrderChoice == 'y' || addAnotherProductToTheOrderChoice == 'n'))
            {
                cout << "That is not a valid entry.  Please enter y or n." << endl;
                continue;
            }
            else if (order.numProdOrdered == 10)
            {
                cout << "Maximum number of products ordered." << endl;
                cout << endl;
                break;
            }
            
            switch (addAnotherProductToTheOrderChoice)
            {
            case 'y':
            {
                continue;
            }
            case 'n':
            {
                break;
            }
            }

        } while (!(addAnotherProductToTheOrderChoice == 'y' || addAnotherProductToTheOrderChoice == 'n'));
    } while (order.numProdOrdered < 10);

    // calculate subtotal and total weight using a for loop
    for (i = 0; i < order.numProdOrdered; i++)
    {
        order.subTotal += order.products[i].price;
        order.totalWeight += order.products[i].weight;
    }

    // calculate shipping cost using a formula
    order.shippingCost = (0.58 * (order.totalWeight / 28.35));
    
    // end program
    return;

}

// Takes information about a mold and prints it to a file or the console
void printProduct(ostream& printTheProduct, moldType mold)
{
    // output product to file or console
    printTheProduct << mold.shape << " - ";
    if (mold.size == S)
    {
        printTheProduct << "Small ";
    }
    else if (mold.size == M)
    {
        printTheProduct << "Medium ";
    }
    else if (mold.size == L)
    {
        printTheProduct << "Large ";
    }
    else
    {
        printTheProduct << "Error ";
    }
    printTheProduct << "$" << mold.price << " " << fixed << showpoint << setprecision(2) << mold.weight << "g" << endl;

    return;
}
// print out order to file or to console
void printOrder(ostream& printTheOrder, orderType& order)
{
    // print out customer information
    printTheOrder << "Customer: " << order.customer.fname << " " << order.customer.lname << endl;
    printTheOrder << order.customer.address << endl;
    printTheOrder << order.customer.cityStateAndZipCode << endl;
    printTheOrder << endl;

    // print out products ordered
    printTheOrder << "Products Ordered:" << endl;

    // for loop to handle printing out objects ordered
    for (int i = 0; i < order.numProdOrdered; i++)
    {
        printProduct(printTheOrder, order.products[i]);
    }

    printTheOrder << fixed << showpoint << setprecision(2) << endl;
    printTheOrder << "Subtotal:  $" << order.subTotal << endl;
    printTheOrder << "Total Weight: " << order.totalWeight << "g" << endl;
    printTheOrder << "Shipping Cost:  $" << order.shippingCost << endl;
    printTheOrder << "Total Cost:  $" << (order.subTotal + order.shippingCost) << endl;

    return;
}