/* Program name: M06_Part_B_Lecture_Lab_Activity.cpp
*  Author: Kyle Ingersoll
*  Date last modified: 10/2/2023
*  Purpose: Prompts user for any number of scores, then finds the lowest, highest, and average scores.
*/

#include <iostream>

using namespace std;

int main()
{   
    // declare variables
    float scores[10];
    int i = 0;

    // prompt user that the program allows you to enter 10 scores
    cout << "The program allows you to enter 10 scores" << endl;

    // do while loop to enter scores
    do
    {
        cout << "Enter score " << endl;
        cin >> scores[i];
        if (!(cin))
        {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "Enter a number" << endl;
            continue;
        }
        i++;
    } 
    while (i < 10);
    

    // for loop to find the lowest, highest, and average scores
    float lowestScore = scores[0], highestScore = scores[0], averageScore = 0, totalScore = 0;

    for (i = 0; i < 10; i++)
    {
        totalScore += scores[i];

        if (scores[i] > highestScore)
        {
            highestScore = scores[i];
        }
        else if (scores[i] < lowestScore)
        {
            lowestScore = scores[i];
        }
    }

    // output lowest, highest, and average scores
    cout << "Lowest score is " << lowestScore << endl;
    cout << "Highest score is " << highestScore << endl;
    cout << "Average score is " << totalScore / i << endl;
    
    return 0;
}

