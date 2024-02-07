/* Program name: main.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 10/1/2023
*  Purpose: This program converts between weight and density measurements for bakers using functions.
*/

// header files
#include <iostream> // header file for cin and cout
#include <iomanip> // header file for setprecision function
#include <string> // header file for string data type
#include <cctype> // header file for tolower function
#include <cstring> // header file for manipulation of strings

using namespace std; // using standard namespace for simplicity's sake

// function prototypes
string getIngredient();
double getDensity(string ingredientName);
double getWeight();
double getVolume();
double convertWeight(double weight, double density);
double convertVolume(double volume, double density);

int main()
{
	// variable declaration
	string ingredientName;
	char weightOrVolumeCharacter;
	double density = 0, weight = 0, volume = 0;
	bool sentinelValue = false;

	// output greeting to the user and explain to user what the program does
	cout << "Welcome to the baking converter." << endl;
	cout << "This program takes a baking ingredient and converts a weight to a volume unit or a volume to a weight unit." << endl;

	// get the ingredient from the user, check it against the table, and then calculate it's density
	ingredientName = getIngredient();
	density = getDensity(ingredientName);

	do
	{
		/* Program name: main.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 9/28/2023
*  Purpose: This program converts between weight and density measurements for bakers using functions.
*/

// header files
#include <iostream> // header file for cin and cout
#include <iomanip> // header file for setprecision function
#include <string> // header file for string data type

		using namespace std; // using standard namespace for simplicity's sake

		// function prototypes
		string getIngredient();
		double getDensity(string ingredientName);
		double getWeight();
		double getVolume();
		double convertWeight(double weight, double density);
		double convertVolume(double volume, double density);

		int main()
		{
			// variable declaration
			string ingredientName;
			char weightOrVolumeCharacter;
			double density = 0, weight = 0, volume = 0;
			bool sentinelValue = false;

			// output greeting to the user and explain to user what the program does
			cout << "Welcome to the baking converter." << endl;
			cout << "This program takes a baking ingredient and converts a weight to a volume unit or a volume to a weight unit." << endl;

			// get the ingredient from the user, check it against the table, and then calculate it's density
			ingredientName = getIngredient();
			density = getDensity(ingredientName);

			do
			{


				// prompt user to input whether they want to convert from weight or volume
				cout << "Do you want to convert from weight or volume? (Enter W or V):";
				cin >> weightOrVolumeCharacter;

				// check to see if character is correct and get and calculate weight or density depending on the user's choice
				switch (weightOrVolumeCharacter)
				{
				case 'w':
				{
					weight = getWeight();
					volume = convertWeight(weight, density);
					cout << fixed << showpoint << setprecision(4) << weight << " g of " << ingredientName << " is " << volume << " ml" << endl;
					sentinelValue = true;
					break;

				}
				case 'W':
				{
					weight = getWeight();
					volume = convertWeight(weight, density);
					cout << fixed << showpoint << setprecision(4) << weight << " g of " << ingredientName << " is " << volume << " ml" << endl;
					sentinelValue = true;
					break;
				}
				case 'v':
				{
					volume = getVolume();
					weight = convertVolume(volume, density);
					cout << fixed << showpoint << setprecision(4) << volume << " ml of " << ingredientName << " is " << weight << " g" << endl;
					sentinelValue = true;
					break;
				}
				case 'V':
				{
					volume = getVolume();
					weight = convertVolume(volume, density);
					cout << fixed << showpoint << setprecision(4) << volume << " ml of " << ingredientName << " is " << weight << " g" << endl;
					sentinelValue = true;
					break;
				}
				default:
				{
					break;
				}

				}
			} while (sentinelValue == false);



			return 0;
		}

		// function definitions

		// gets the ingredient from the user and validates it against the ingredients in the table
		string getIngredient()
		{
			// initalize variables
			string ingredientName;
			bool exitValue = false;

			do
			{
				// prompt user for the ingredient name
				cout << "Enter the name of the ingredient: ";
				getline(cin, ingredientName); // since coco powder is two words, we need getline to include both words and the space between them

				// if else structure to check ingredient name in the table regardless of capitalization of the first letter or of all letters
				// switches don't allow the use of string data type
				if (ingredientName == "Sugar")
				{
					exitValue = true;
				}
				else if (ingredientName == "sugar")
				{
					exitValue = true;
				}
				else if (ingredientName == "SUGAR")
				{
					exitValue = true;
				}
				else if (ingredientName == "Flour")
				{
					exitValue = true;
				}
				else if (ingredientName == "flour")
				{
					exitValue = true;
				}
				else if (ingredientName == "FLOUR")
				{
					exitValue = true;
				}
				else if (ingredientName == "Coco Powder")
				{
					exitValue = true;
				}
				else if (ingredientName == "coco powder")
				{
					exitValue = true;
				}
				else if (ingredientName == "COCO POWDER")
				{
					exitValue = true;
				}
				else if (ingredientName == "Honey")
				{
					exitValue = true;
				}
				else if (ingredientName == "honey")
				{
					exitValue = true;
				}
				else if (ingredientName == "HONEY")
				{
					exitValue = true;
				}
				else if (ingredientName == "Egg")
				{
					exitValue = true;
				}
				else if (ingredientName == "egg")
				{
					exitValue = true;
				}
				else if (ingredientName == "EGG")
				{
					exitValue = true;
				}
				else if (ingredientName == "Milk")
				{
					exitValue = true;
				}
				else if (ingredientName == "milk")
				{
					exitValue = true;
				}
				else if (ingredientName == "MILK")
				{
					exitValue = true;
				}
				else if (ingredientName == "Water")
				{
					exitValue = true;
				}
				else if (ingredientName == "water")
				{
					exitValue = true;
				}
				else if (ingredientName == "WATER")
				{
					exitValue = true;
				}
				else if (ingredientName == "Oil")
				{
					exitValue = true;
				}
				else if (ingredientName == "oil")
				{
					exitValue = true;
				}
				else if (ingredientName == "OIL")
				{
					exitValue = true;
				}
				else
				{
					cout << "I don't know that ingredient. Here is a list of ingredients I know:" << endl;
					cout << "Sugar, Flour, Coco Powder, Honey, Egg, Milk, Water, and Oil" << endl;
					continue;
				}

			} while (exitValue == false);

			return ingredientName;
		}
		// returns density using variations of the ingredient name
		double getDensity(string ingredientName)
		{
			if (ingredientName == "Sugar")
			{
				return 1.59;
			}
			else if (ingredientName == "sugar")
			{
				return 1.59;
			}
			else if (ingredientName == "SUGAR")
			{
				return 1.59;
			}
			else if (ingredientName == "Flour")
			{
				return 0.762;
			}
			else if (ingredientName == "flour")
			{
				return 0.762;
			}
			else if (ingredientName == "FLOUR")
			{
				return 0.762;
			}
			else if (ingredientName == "Coco Powder")
			{
				return 1.35;
			}
			else if (ingredientName == "coco powder")
			{
				return 1.35;
			}
			else if (ingredientName == "COCO POWDER")
			{
				return 1.35;
			}
			else if (ingredientName == "Honey")
			{
				return 1.38;
			}
			else if (ingredientName == "honey")
			{
				return 1.38;
			}
			else if (ingredientName == "HONEY")
			{
				return 1.38;
			}
			else if (ingredientName == "Egg")
			{
				return 1.031;
			}
			else if (ingredientName == "egg")
			{
				return 1.031;
			}
			else if (ingredientName == "EGG")
			{
				return 1.031;
			}
			else if (ingredientName == "Milk")
			{
				return 1.025;
			}
			else if (ingredientName == "milk")
			{
				return 1.025;
			}
			else if (ingredientName == "MILK")
			{
				return 1.025;
			}
			else if (ingredientName == "Water")
			{
				return 0.997;
			}
			else if (ingredientName == "water")
			{
				return 0.997;
			}
			else if (ingredientName == "WATER")
			{
				return 0.997;
			}
			else if (ingredientName == "Oil")
			{
				return 0.91;
			}
			else if (ingredientName == "oil")
			{
				return 0.91;
			}
			else if (ingredientName == "OIL")
			{
				return 0.91;
			}
			else
			{
				cout << "I don't know that ingredient. Here is a list of ingredients I know:" << endl;
				cout << "Sugar, Flour, Coco Powder, Honey, Egg, Milk, Water, and Oil" << endl;
				return -1;
			}
		}
		// prompts the user for the weight, verifies the answer, and then returns the weight
		double getWeight()
		{
			double weight = 0;
			do
			{

				cout << "Enter the weight of your ingredient in g :";
				cin >> weight;

				if (!(cin))
				{
					cin.clear();
					cin.ignore(200, '\n');
					weight = 0;
					cout << "You entered something that is not a number. Please Try again." << endl;
					continue;
				}
				else if (weight > 0)
				{
					break;
				}
				else
				{
					cout << "The ingredient weight must be greater than 0." << endl;
					continue;
				}
			} while (weight <= 0);
			return weight;
		}
		// prompts the user for the volume, verifies the answer, and then returns the volume
		double getVolume()
		{
			double volume = 0;
			do
			{

				cout << "Enter the volume of your ingredient in ml:";
				cin >> volume;

				if (!(cin))
				{
					cin.clear();
					cin.ignore(200, '\n');
					volume = 0;
					cout << "You entered something that is not a number. Please Try again." << endl;
					continue;
				}
				else if (volume > 0)
				{
					break;
				}
				else
				{
					cout << "The ingredient volume must be greater than 0." << endl;
					continue;
				}
			} while (volume <= 0);
			return volume;
		}
		// converts the weight into volume, and then returns volume
		double convertWeight(double weight, double density)
		{
			return weight / density;
		}
		// converts the volume into weight, and then returns weight
		double convertVolume(double volume, double density)
		{
			return volume * density;
		}