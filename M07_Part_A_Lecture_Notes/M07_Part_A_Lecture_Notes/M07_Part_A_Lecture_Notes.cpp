/* Program name:  M07_Part_A_Lecture_Notes.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 10/9/2023
*  Purpose: To practice using the struct data type.
*/

#include <iostream>
#include <string>

using namespace std;

// declare a structure about students
struct studentType {
    string firstName, lastName;
    int testScore[3]; // array of scores
    // float GPA;

};

// function to return a structure 
studentType input();

// pass a struct to a function
// void calcGrade(studentType x);


int main()
{
    float avg;
    studentType s;

    s = input();
    avg = (s.testScore[0] + s.testScore[1] + s.testScore[2]) / 3;

        if (avg >= 90)
        {
            cout << s.firstName << " " << avg << " " << "A" << endl;
        }
        else if (avg>= 80 && avg <= 90)
        {
            cout << s.firstName << " " << avg << " " << "B" << endl;
        }
        else if (avg >= 70 && avg <= 80)
        {
            cout << s.firstName << " " << avg << " " << "C" << endl;
        }
        else if (avg >= 60 && avg <= 70)
        {
            cout << s.firstName << " " << avg << " " << "D" << endl;
        }
        else
        {
            cout << s.firstName << " " << avg << " " << "F" << endl;
        }

    /*
    // make a structure variable
    studentType student, student1;
    student.firstName = "Tina";
    student1.firstName = "Ponal";

    cout << "The student's name is " << student.firstName << endl;
    // allow user to input value into structure
    cout << "Enter a student's first name" << endl;
    cin >> student.firstName;

    cout << "The student's name is " << student.firstName << endl;

    // populate an array within a structure
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter test score " << i + 1 << endl;
        cin >> student.testScore[i];
    }

    calcGrade(student); // call the function with the structure variable
    */


    return 0;
}

// pass a struct to a function
/*
void calcGrade(studentType x)
{
    x.GPA = (x.testScore[0] + x.testScore[1] + x.testScore[2]) / 3;

    if (x.GPA >= 90)
    {
        cout << x.firstName << " " << x.GPA << " " << "A" << endl;
    }
    else if (x.GPA >= 80 && x.GPA <= 90)
    {
        cout << x.firstName << " " << x.GPA << " " << "B" << endl;
    }
    else if (x.GPA >= 70 && x.GPA <= 80)
    {
        cout << x.firstName << " " << x.GPA << " " << "C" << endl;
    }
    else if (x.GPA >= 60 && x.GPA <= 70)
    {
        cout << x.firstName << " " << x.GPA << " " << "D" << endl;
    }
    else
    {
        cout << x.firstName << " " << x.GPA << " " << "F" << endl;
    }
}
*/

studentType input()
{
    studentType newStudent;

    cout << " Enter student information " << endl;
    cout << "First name" << endl;
    cin >> newStudent.firstName;
    cout << "Last name" << endl;
    cin >> newStudent.lastName;
    
    // populate an array within a structure
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter test score " << i + 1 << endl;
        cin >> newStudent.testScore[i];
    }

    return newStudent;
}