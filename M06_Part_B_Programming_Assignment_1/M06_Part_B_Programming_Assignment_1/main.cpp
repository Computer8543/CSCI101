/* Program name: main.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 10/4/2023
*  Purpose: To sort an array of student scores and output the highest score, the lowest score, the average score, and the median score per test.
*/

#include <iostream> // header file for cout and cin functions
#include <iomanip> // header file for setprecision function
#include <fstream> // header file for file input and output functions
#include <utility> // header file for swap function

using namespace std; // use standard namespace for simplicity's sake

// function prototypes
void getHighScoreIndex(double scores[][5], int numRows, int colToAnalyze, int& highScoreIndex);
void getLowScoreIndex(double scores[][5], int numRows, int colToAnalyze, int& lowScoreIndex);
void getAverageScore(double scores[][5], int numRows, int colToAnalyze, double& average);
void getMedianScore(double scores[][5], int numRows, int colToAnalyze, double& median);
void selectionSort(double scoreColumn[], int numItems);

int main()
{
    //declare variables
    double scores[20][5] = { 0 };
    int i, j, numOfRows = 0;
    //declare ifstream variable
    ifstream readScores;

    // open file 
    readScores.open("grades.txt");

    // populate array 
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 5; j++)
        {
            readScores >> scores[i][j];
        }
    }

    // close file 
    readScores.close();

    // check number of rows with actual data in array
    for (i = 0; i < 20; i++)
    {
        if (scores[i][0] != 0)
        {
            numOfRows++;
        }
    }

    // initalize more variables for the getHighScoreIndex

    int highScoreIndex, lowScoreIndex;
    double average, median;

    // begin output of data

    cout << "Grade Statistics:" << endl;


    // get highest, lowest, average, and median scores for tests 1 through 5
    for (i = 0; i < 5; i++)
    {
        getHighScoreIndex(scores, numOfRows, i, highScoreIndex);
        getLowScoreIndex(scores, numOfRows, i, lowScoreIndex);
        getAverageScore(scores, numOfRows, i, average);
        getMedianScore(scores, numOfRows, i, median);

        cout << "Test" << i + 1 << endl;
        cout << fixed << showpoint << setprecision(2) << '\t' << "Highest Score: " << scores[highScoreIndex][i] << endl;
        cout << fixed << showpoint << setprecision(2) << '\t' << "Lowest Score: " << scores[lowScoreIndex][i] << endl;
        cout << fixed << showpoint << setprecision(2) << '\t' << "Average Score: " << average << endl;
        cout << fixed << showpoint << setprecision(2) << '\t' << "Median Score: " << median << endl;
    }

    return 0;
}
// Function goes across the array to find the index of the largest score in the array
void getHighScoreIndex(double scores[][5], int numRows, int colToAnalyze, int& highScoreIndex)
{
    int i;
    highScoreIndex = 0;
    for (i = 0; i < numRows; i++)
    {
        if (scores[i][colToAnalyze] > scores[highScoreIndex][colToAnalyze])
        {
            highScoreIndex = i;
        }
    }
}
// Function goes across the array to find the index of the smallest score in the array
void getLowScoreIndex(double scores[][5], int numRows, int colToAnalyze, int& lowScoreIndex)
{
    int i;
    lowScoreIndex = 0;
    for (i = 0; i < numRows; i++)
    {
        if (scores[i][colToAnalyze] == 0)
        {
            continue;
        }
        else if (scores[i][colToAnalyze] < scores[lowScoreIndex][colToAnalyze])
        {
            lowScoreIndex = i;
        }

    }
}
// Function adds up all the values in the column, and then divides them by the number of rows to find the average
void getAverageScore(double scores[][5], int numRows, int colToAnalyze, double& average)
{
    int i;
    double total = 0;
    average = 0;

    for (i = 0; i < numRows; i++)
    {
        total += scores[i][colToAnalyze];
    }
    average = total / numRows;
}
// The function calculates the median score by first populating a column array, then sorting it, then by determining if the number of rows is even or not.
// If it is even, the 2 middle elements get added together and then divided by 2, if it is odd, the middle one is chosen
void getMedianScore(double scores[][5], int numRows, int colToAnalyze, double& median)
{
    int i;
    double column[20] = { 0 };

    for (i = 0; i < 20; i++)
    {
        column[i] = scores[i][colToAnalyze];
    }

    selectionSort(column, numRows);

    if (numRows % 2 == 0)
    {
        median = ((column[((numRows / 2) - 1)] + column[((numRows / 2))]) / 2);
    }
    else
    {
        median = column[((numRows / 2))];
    }
}
// Function goes across the array to find the smallest element, and swap the smallest element with the first, then second, then third element and so on
void selectionSort(double scoreColumn[], int numItems)
{
    int i, j, minimumElement;

    for (i = 0; i < (numItems - 1); i++)
    {
        minimumElement = i;

        for (j = (i + 1); j < numItems; j++)
        {

            if (scoreColumn[j] < scoreColumn[minimumElement])
            {
                minimumElement = j;
            }
        }
        if (minimumElement != i)
            swap(scoreColumn[minimumElement], scoreColumn[i]);

    }
}






