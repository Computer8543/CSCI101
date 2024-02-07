/* Program name: main.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 10/9/2023
*  Purpose: The program creates new characters for an RPG using structs.
*/

#include <iostream> // header file for cin and cout
#include <string> // header file for string data type

using namespace std; // use standard namespace for simplicity's sake

// declare enumeration for character class type
enum characterClassType {FIGHT, ROGUE, MAGIC, CLERIC};

// declare character type struct
struct characterType 
{
	string name;
	double hp, mp;
	int strength, dexterity, intelligence, speed, endurance, faith;
	characterClassType characterClass;

};
// function prototype
characterType getCharacterNameAndClass(bool& newCharacterValid);
void displayCharacter(characterType theCharacter);

int main()
{
	// declare variables 
	characterType characters[10];
	int numberOfCharactersCreated = 0;
	char createAnotherCharacterChoice;
	bool newCharacterValid = false;
	
	// welcome user to the program
	cout << "Welcome to the Character Creator!" << endl;

	characters[numberOfCharactersCreated] = getCharacterNameAndClass(newCharacterValid);

	if (newCharacterValid == true)
	{
		// increase number of characters created by 1
		numberOfCharactersCreated++;
	}

	do
	{
		// prompt user if they want to create another character and have that choice be reduced to the lowercase version of itself
		cout << "Do you want to create another character (y or n)? ";
		cin >> createAnotherCharacterChoice;
		cout << endl;
		createAnotherCharacterChoice = tolower(createAnotherCharacterChoice);

		// switch structure to handle the choice to create another character
		switch (createAnotherCharacterChoice)
		{
		case 'y':
		{
			if (numberOfCharactersCreated < 10)
			{
				cin.clear();
				cin.ignore(200, '\n');
				characters[numberOfCharactersCreated] = getCharacterNameAndClass(newCharacterValid);
				if (newCharacterValid == true)
				{
					numberOfCharactersCreated++;
				}
				continue;
			}
			else
			{
				cout << endl;
				cout << "You have entered the max number of characters. The program will now exit." << endl;
				cout << endl;
				cout << "Here are the characters you created:" << endl;

				for (int i = 0; i < 10; i++)
				{
					displayCharacter(characters[i]);
				}

				return 0;
			}
		}
		case 'n':
		{
			cout << endl;
			cout << "Here are the characters you created:" << endl;

			for (int i = 0; i < (numberOfCharactersCreated + 1); i++)
			{
				displayCharacter(characters[i]);
			}

			return 0;
		}
		default:
		{
			cout << "I was expecting y or n." << endl;
			continue;
		}
		}

	} while (numberOfCharactersCreated < 11);
}

// prompt user for character name and class and return the new character struct
characterType getCharacterNameAndClass(bool& newCharacterValid)
{
	// declare variables
	int characterClassChoice = 0;
	characterType newCharacter;

	// prompt user for character's name
	cout << "What is your character's name:";
	getline(cin, newCharacter.name);
	cout << endl;

	
		// prompt user for character class
		cout << "What character class do you want " << newCharacter.name << " to be?" << endl;
		cout << "1. Fighter Class" << endl;
		cout << "2. Rogue Class" << endl;
		cout << "3. Magician Class" << endl;
		cout << "4. Cleric Class" << endl;
		cin >> characterClassChoice;
	
	do
	{
		// selection structure to handle input failure, the user inputting a number less than 1 or greater than 4, and 
		if ((!cin))
		{
			cin.clear();
			cin.ignore(200, '\n');
			characterClassChoice = 0;
			cout << "You entered something that is not a number. Please Try again." << endl;
			cout << "That is not a valid choice. Please choose the class by number from the list." << endl;
			cin >> characterClassChoice;
			continue;
		}
		else if (characterClassChoice < 1 || characterClassChoice > 4)
		{
			cout << "That is not a valid choice. Please choose the class by number from the list." << endl;
			cin >> characterClassChoice;
			continue;
		}
		else
		{
			break;
		}
	} while (characterClassChoice < 1 || characterClassChoice > 4);

	// sets up stats for player class choice
	switch (characterClassChoice)
	{
	case 1:
	{
		// sets up struct member values for Fighter Class
		newCharacter.characterClass = FIGHT;
		newCharacter.hp = 30;
		newCharacter.mp = 0;
		newCharacter.strength = 16;
		newCharacter.dexterity = 10;
		newCharacter.intelligence = 5;
		newCharacter.speed = 8;
		newCharacter.endurance = 15;
		newCharacter.faith = 5;
		newCharacterValid = true;
		return newCharacter;
	}
	case 2:
	{
		// sets up struct member values for Rogue Class
		newCharacter.characterClass = ROGUE;
		newCharacter.hp = 20;
		newCharacter.mp = 0;
		newCharacter.strength = 10;
		newCharacter.dexterity = 16;
		newCharacter.intelligence = 16;
		newCharacter.speed = 15;
		newCharacter.endurance = 8;
		newCharacter.faith = 5;
		newCharacterValid = true;
		return newCharacter;
	}
	case 3:
	{
		// sets up struct member values for Magician Class
		newCharacter.characterClass = MAGIC;
		newCharacter.hp = 25;
		newCharacter.mp = 20;
		newCharacter.strength = 5;
		newCharacter.dexterity = 10;
		newCharacter.intelligence = 16;
		newCharacter.speed = 16;
		newCharacter.endurance = 5;
		newCharacter.faith = 8;
		newCharacterValid = true;
		return newCharacter;
	}
	case 4:
	{
		// sets up struct member values for Cleric Class
		newCharacter.characterClass = CLERIC;
		newCharacter.hp = 20;
		newCharacter.mp = 20;
		newCharacter.strength = 5;
		newCharacter.dexterity = 10;
		newCharacter.intelligence = 8;
		newCharacter.speed = 16;
		newCharacter.endurance = 5;
		newCharacter.faith = 16;
		newCharacterValid = true;
		return newCharacter;
	}
	default:
	{
		newCharacterValid = false;
		break;
	}
	}

	// return the struct we have created to main() and end the function
	return newCharacter;
}

// Displays to the console the stats and information about a single character.
void displayCharacter(characterType theCharacter)
{
	switch (theCharacter.characterClass)
	{
	case FIGHT:
	{
		cout << theCharacter.name << " the Fighter stats:" << endl;
		cout << "HP: " << theCharacter.hp << endl;
		cout << "MP: " << theCharacter.mp << endl;
		cout << "Strength: " << theCharacter.strength << endl;
		cout << "Dexterity: " << theCharacter.dexterity << endl;
		cout << "Intelligence: " << theCharacter.intelligence << endl;
		cout << "Speed: " << theCharacter.speed << endl;
		cout << "Endurance: " << theCharacter.endurance << endl;
		cout << "Faith: " << theCharacter.faith << endl;
		cout << endl;
		break;
	}
	case ROGUE:
	{
		cout << theCharacter.name << " the Rogue stats:" << endl;
		cout << "HP: " << theCharacter.hp << endl;
		cout << "MP: " << theCharacter.mp << endl;
		cout << "Strength: " << theCharacter.strength << endl;
		cout << "Dexterity: " << theCharacter.dexterity << endl;
		cout << "Intelligence: " << theCharacter.intelligence << endl;
		cout << "Speed: " << theCharacter.speed << endl;
		cout << "Endurance: " << theCharacter.endurance << endl;
		cout << "Faith: " << theCharacter.faith << endl;
		cout << endl;
		break;
	}
	case MAGIC:
	{
		cout << theCharacter.name << " the Magician stats:" << endl;
		cout << "HP: " << theCharacter.hp << endl;
		cout << "MP: " << theCharacter.mp << endl;
		cout << "Strength: " << theCharacter.strength << endl;
		cout << "Dexterity: " << theCharacter.dexterity << endl;
		cout << "Intelligence: " << theCharacter.intelligence << endl;
		cout << "Speed: " << theCharacter.speed << endl;
		cout << "Endurance: " << theCharacter.endurance << endl;
		cout << "Faith: " << theCharacter.faith << endl;
		cout << endl;
		break;
	}
	case CLERIC:
	{
		cout << theCharacter.name << " the Cleric stats:" << endl;
		cout << "HP: " << theCharacter.hp << endl;
		cout << "MP: " << theCharacter.mp << endl;
		cout << "Strength: " << theCharacter.strength << endl;
		cout << "Dexterity: " << theCharacter.dexterity << endl;
		cout << "Intelligence: " << theCharacter.intelligence << endl;
		cout << "Speed: " << theCharacter.speed << endl;
		cout << "Endurance: " << theCharacter.endurance << endl;
		cout << "Faith: " << theCharacter.faith << endl;
		cout << endl;
		break;
	}
	}
	return;
}