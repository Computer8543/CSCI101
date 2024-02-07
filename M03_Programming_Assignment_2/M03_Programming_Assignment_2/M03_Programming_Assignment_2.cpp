/* Program name: main.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 9/16/2023
*  Purpose: The program reads data from ghosts.txt to determine whether the place is haunted or not. If events add up to more than 15 points,
*			the program states "This place is haunted." Otherwise the program states "This place is probably not haunted." Before the program finishes,
*			the program states, "Great job! On to the next one."
*/

#include <iostream> // for using cin and cout
#include <string> // for using the string data type
#include <fstream> // for reading and writing to files

using namespace std; // initialize standard namespace

int main()
{
	// declare variables
	char ghostHuntEvent;
	int	ghostHuntEventTimesOccurred;
	int totalHauntingScore = 0;

	// declare ifstream variable
	ifstream readData;

	// first output of program 
	cout << "Analyzing Ghost Hunt Data ... " << endl;

	// associate ifstream variable with the ghosts.txt file
	readData.open("ghosts.txt");

	// associate ghosts.txt data with the ifstream variable for the first time
	readData >> ghostHuntEvent;
	readData >> ghostHuntEventTimesOccurred;

	// switch structure for the first line in ghosts.txt
	switch (ghostHuntEvent)
	{
	case 'E':
		totalHauntingScore += (ghostHuntEventTimesOccurred * 3);
		cout << "Found " << ghostHuntEventTimesOccurred << " instances of EVP (Electronic Voice Phenomena)." << endl;
		break;

	case 'S':
		totalHauntingScore += (ghostHuntEventTimesOccurred * 1);
		cout << "Found " << ghostHuntEventTimesOccurred << " instances of shadows or orbs." << endl;
		break;

	case 'F':
		totalHauntingScore += (ghostHuntEventTimesOccurred * 2);
		cout << "Found " << ghostHuntEventTimesOccurred << " instances of footsteps." << endl;
		break;

	case 'A':
		totalHauntingScore += (ghostHuntEventTimesOccurred * 5);
		cout << "Found " << ghostHuntEventTimesOccurred << " instances of a full body apparition." << endl;
		break;

	case 'O':
		totalHauntingScore += (ghostHuntEventTimesOccurred * 5);
		cout << "Found " << ghostHuntEventTimesOccurred << " instances of objects moving on their own." << endl;
		break;

	case 'D':
		totalHauntingScore += (ghostHuntEventTimesOccurred * 3);
		cout << "Found " << ghostHuntEventTimesOccurred << " instances of doors shutting on their own." << endl;
		break;

	case 'T':
		totalHauntingScore += (ghostHuntEventTimesOccurred * 2);
		cout << "Found " << ghostHuntEventTimesOccurred << " hotspots or cold spots on the thermocamera." << endl;
		break;

	default:
		cout << "Invalid data detected from ghosts.txt. Program closing now" << endl;
		readData.close();
		return 1;
	}

	// associate ghosts.txt data with the ifstream variable for the second time
	readData >> ghostHuntEvent;
	readData >> ghostHuntEventTimesOccurred;

	// switch structure for the second line in ghosts.txt
	switch (ghostHuntEvent)
	{
	case 'E':
		totalHauntingScore += (ghostHuntEventTimesOccurred * 3);
		cout << "Found " << ghostHuntEventTimesOccurred << " instances of EVP (Electronic Voice Phenomena)." << endl;
		break;

	case 'S':
		totalHauntingScore += (ghostHuntEventTimesOccurred * 1);
		cout << "Found " << ghostHuntEventTimesOccurred << " instances of shadows or orbs." << endl;
		break;

	case 'F':
		totalHauntingScore += (ghostHuntEventTimesOccurred * 2);
		cout << "Found " << ghostHuntEventTimesOccurred << " instances of footsteps." << endl;
		break;

	case 'A':
		totalHauntingScore += (ghostHuntEventTimesOccurred * 5);
		cout << "Found " << ghostHuntEventTimesOccurred << " instances of a full body apparition." << endl;
		break;

	case 'O':
		totalHauntingScore += (ghostHuntEventTimesOccurred * 5);
		cout << "Found " << ghostHuntEventTimesOccurred << " instances of objects moving on their own." << endl;
		break;

	case 'D':
		totalHauntingScore += (ghostHuntEventTimesOccurred * 3);
		cout << "Found " << ghostHuntEventTimesOccurred << " instances of doors shutting on their own." << endl;
		break;

	case 'T':
		totalHauntingScore += (ghostHuntEventTimesOccurred * 2);
		cout << "Found " << ghostHuntEventTimesOccurred << " hotspots or cold spots on the thermocamera." << endl;
		break;

	default:
		cout << "Invalid data detected from ghosts.txt. Program closing now" << endl;
		readData.close();
		return 1;
	}

	// associate ghosts.txt data with the ifstream variable for the third time
	readData >> ghostHuntEvent;
	readData >> ghostHuntEventTimesOccurred;

	// switch structure for the third line in ghosts.txt
	switch (ghostHuntEvent)
	{
	case 'E':
		totalHauntingScore += (ghostHuntEventTimesOccurred * 3);
		cout << "Found " << ghostHuntEventTimesOccurred << " instances of EVP (Electronic Voice Phenomena)." << endl;
		break;

	case 'S':
		totalHauntingScore += (ghostHuntEventTimesOccurred * 1);
		cout << "Found " << ghostHuntEventTimesOccurred << " instances of shadows or orbs." << endl;
		break;

	case 'F':
		totalHauntingScore += (ghostHuntEventTimesOccurred * 2);
		cout << "Found " << ghostHuntEventTimesOccurred << " instances of footsteps." << endl;
		break;

	case 'A':
		totalHauntingScore += (ghostHuntEventTimesOccurred * 5);
		cout << "Found " << ghostHuntEventTimesOccurred << " instances of a full body apparition." << endl;
		break;

	case 'O':
		totalHauntingScore += (ghostHuntEventTimesOccurred * 5);
		cout << "Found " << ghostHuntEventTimesOccurred << " instances of objects moving on their own." << endl;
		break;

	case 'D':
		totalHauntingScore += (ghostHuntEventTimesOccurred * 3);
		cout << "Found " << ghostHuntEventTimesOccurred << " instances of doors shutting on their own." << endl;
		break;

	case 'T':
		totalHauntingScore += (ghostHuntEventTimesOccurred * 2);
		cout << "Found " << ghostHuntEventTimesOccurred << " hotspots or cold spots on the thermocamera." << endl;
		break;

	default:
		cout << "Invalid data detected from ghosts.txt. Program closing now" << endl;
		readData.close();
		return 1;
	}
	// state the haunting score for this place
	cout << "The haunting score for this place is " << totalHauntingScore << "." << endl;

	// two way selection function to determine if the place is haunted or not
	if (totalHauntingScore > 15)
		cout << "This place is haunted." << endl;
	else
		cout << "This place is probably not haunted." << endl;

	// prepare user for the program ending
	cout << "Great job! On to the next one." << endl;

	// close the program
	readData.close();
	return 0;
}
