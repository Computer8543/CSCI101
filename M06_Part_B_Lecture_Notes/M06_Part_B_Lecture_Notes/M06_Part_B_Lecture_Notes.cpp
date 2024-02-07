// M06_Part_B_Lecture_Notes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;
/*
void calcAvg(int list[], int num)
{
    int i, total = 0;

    for (i = 0; i < num; i++)
    {
        total += list[i];
    }
    cout << "The average is " << total / i << endl;
}
*/
float calcAvg(int list[], int num)
{
    int i, total = 0;
    float avg;

    for (i = 0; i < num; i++)
    {
        total += list[i];
    }
    avg = total / i;
    return avg;
}
void outputGrades(string list1[], int list2[], int i, int j)
{
    for (int z = 0; z < i; z++)
    {
        cout << list1[z] << "\t" << list2[z] << endl;
    }
}

int main()
{
    // create an array to accept 5 scores from a user and calculate the average
    /*
    int score[5];
    cout << "Enter a score " << endl;
    cin >> score[0];
    cout << "Enter a score " << endl;
    cin >> score[1];
    cout << "Enter a score " << endl;
    cin >> score[2];
    cout << "Enter a score " << endl;
    cin >> score[3];
    cout << "Enter a score " << endl;
    cin >> score[4];
    */
    
    // populate array with while loop
    /*
    int score[5];
    int i = 0;

    while (i < 5)
    {
        cout << "Enter a score " << endl;
        cin >> score[i];
        i++;
    }
    */
    // populate array with for loop
    /*
    int score[5];
    int i;

    for (i = 0; i < 5; i++)
    {
        cout << "Enter a score " << endl;
        cin >> score[i];
    }
    int total;
    total = score[0] + score[1] + score[2] + score[3] + score[4];
    cout << "The average score is " << total / i << endl;
    */
    /*
    int score[5];
    int i;
    int total = 0;
    for (i = 0; i < 5; i++)
    {
        cout << "Enter a score " << endl;
        cin >> score[i];
        total += score[i];
    }
   
    // output items in an array
    for (i = 0; i < 5; i++)
    {
        cout << score[i] << endl;
    }

    // output items in an array in reverse order
    for (i = 4; i > -1; i--)
    {
        cout << score[i] << endl;
    }

    cout << "The average score is " << total / 5 << endl;
    */
    
    // initalize parallel arrays
    /*
    int score[5];
    string students[5];

    int i;
    int total = 0;
    for (i = 0; i < 5; i++)
    {
        cout << "Enter a student name " << endl;
        cin >> students[i];
        cout << "Enter a score for " << students[i] << endl;
        cin >> score[i];
        total += score[i];
    }

    cout << "The average score is " << total / i << endl;

    for (i = 4; i > -1; i--)
    {
        cout << students[i] << "\t" << score[i] << endl;
    }
    */

    /*
    int score[5];
    int i;

    for (i = 0; i < 5; i++)
    {
        cout << "Enter a score " << endl;
        cin >> score[i];
    }
    cout << "The average is " << calcAvg(score, i) << endl; //call to the average function
    */
    
    // initalize parallel arrays
    /*
    int score[5];
    string students[5];

    int i;
    int total = 0;
    for (i = 0; i < 5; i++)
    {
        cout << "Enter a student name " << endl;
        cin >> students[i];
        cout << "Enter a score for " << students[i] << endl;
        cin >> score[i];
        total += score[i];
    }
    outputGrades(students, score, i, i);
    */

    // multi-dimensional array

    int scores[3][4];
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            cout << "Enter score" << endl;
            cin >> scores[i][j];
        }
    }

    // output the multi-dimensional array
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            cout << scores[i][j] << " ";
        }
        cout << endl; // prints new line at the end of each row
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
