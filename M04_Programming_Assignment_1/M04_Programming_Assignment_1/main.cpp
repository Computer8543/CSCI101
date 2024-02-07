/* Program name: main.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 9/16/2023
*  Purpose: The program takes the results of a esports tournament, reads the username and score from the file and outputs that in a formatted manner.
*           The program then keeps track of the top three players and awards a gold metal to the top player, a silver metal to the second best player,
*			and a bronze metal to the third best player.
*/

#include <iostream> // allows for cin and cout 
#include <fstream> // allows to read to and write to a file
#include <string> // allows for the usage of the string data type
#include <iomanip> // allows for manipulation of output

using namespace std; // initialize standard namespace for simplicity's sake.

int main()
{
	// declare variables
	string username;
	int score;
	string goldMedalWinnerUsername, silverMedalWinnerUsername, bronzeMedalWinnerUsername;
	int goldMedalWinnerScore = 0, silverMedalWinnerScore = 0, bronzeMedalWinnerScore = 0;

	// declare ifstream variable
	ifstream readData;

	// open file and associate data with variables
	readData.open("scores.txt");
	readData >> username;
	readData >> score;

	// table heading
	cout << "IvyGames Tournament Results:" << endl;
	cout << setw(35) << setfill('-') << "-" << endl;
	cout << setfill(' ');
	cout << "| " << setw(15) << left << "Username" << "| " << setw(15) << "Score" << "|" << endl;
	cout << setw(35) << setfill('-') << "-" << endl;
	cout << setfill(' ');

	// eof controlled while loop
	while (readData)
	{
		// inital output block 
		cout << setfill(' ');
		cout << "| " << setw(15) << left << username << "| " << setw(15) << score << "|" << endl;
		cout << setw(35) << setfill('-') << "-" << endl;
		cout << setfill(' ');

		// selection structure to handle distribution of gold, silver, and bronze metals.
		if (score > goldMedalWinnerScore)
		{
			// silver goes down to bronze, gold goes down to silver, and current score and username become gold
			bronzeMedalWinnerUsername = silverMedalWinnerUsername;
			bronzeMedalWinnerScore = silverMedalWinnerScore;

			silverMedalWinnerUsername = goldMedalWinnerUsername;
			silverMedalWinnerScore = goldMedalWinnerScore;

			goldMedalWinnerUsername = username;
			goldMedalWinnerScore = score;
		}
		else if (score <= goldMedalWinnerScore && score > silverMedalWinnerScore)
		{
			// silver goes down to bronze, and current score and username become silver
			bronzeMedalWinnerUsername = silverMedalWinnerUsername;
			bronzeMedalWinnerScore = silverMedalWinnerScore;

			silverMedalWinnerUsername = username;
			silverMedalWinnerScore = score;
		}
		else if (score <= goldMedalWinnerScore && score <= silverMedalWinnerScore && score > bronzeMedalWinnerScore)
		{
			// current score and username become bronze
			bronzeMedalWinnerUsername = username;
			bronzeMedalWinnerScore = score;
		}

		// associate next line of data with variables
		readData >> username;
		readData >> score;
	}
	// close file
	readData.close();

	// output gold, silver, and bronze member recipiants and their scores
	cout << "The gold medal winner is " << goldMedalWinnerUsername << " with " << goldMedalWinnerScore << " points." << endl;
	cout << "The silver medal winner is " << silverMedalWinnerUsername << " with " << silverMedalWinnerScore << " points." << endl;
	cout << "The bronze medal winner is " << bronzeMedalWinnerUsername << " with " << bronzeMedalWinnerScore << " points." << endl;
	cout << "Congratulations to the winners! See you at the next tournament." << endl;

	return 0;
}


