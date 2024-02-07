/* Program Name: main.cpp
* Author: Kyle Ingersoll
* Date Last Updated: 9/1/2023
* Purpose: Read data from gradebook.txt and output a table of data to the command line
*/
#include <iostream> // include program input and output
#include <fstream>  // allows reading and writing to files
#include <string>   // include string data type
#include <iomanip>  // allows manipulation of input and output

using namespace std; // initialize standard namespace


int main() // start up main function
{
    // declare variables
    string studentFirstName, studentLastName;
    int studentID;
    float studentPercent;
    char studentGrade;

    // declare fstream variable for input 
    ifstream readData; // this functions like cin
    
    // table heading or row 1 output
    cout << left;
    cout << setfill('-') << setw(17) << "+-" << setw(32) << "+-" << setw(12) << "+-" << setw(12) << "+-" << "+" << endl;
    cout << setfill(' ');
    cout << "| " << setw(15) << "Student Num" << "| " << setw(30) << "Student Name" << "| " << setw(10) << "Percent" << "| " << setw(10) << "Grade" << "|" << endl;
    // deleted lower line from rows 1 to 5 so that they fit together in a table. 
    cout << setfill(' ');

    // associate fstream variables with file
    readData.open("gradebook.txt");
    readData >> studentID;
    readData >> studentFirstName;
    readData >> studentLastName;
    readData >> studentPercent;
    readData >> studentGrade;
    
    // change studentPercent from a decimal number to a percentage
    studentPercent = studentPercent * 100;

    // row 2 output
    // note to self, to adjust for differently sized student names, you want to change the value of setw between studentFirstName and studentLastName.
    // change it a little at a time, not by a lot when doing trial by error. 
    // setw ignores the first object (like a string or integer) placed directly after it in the output, but affects the rest of the objects after.
    cout << left;
    cout << setfill('-') << setw(17) << "+-" << setw(32) << "+-" << setw(12) << "+-" << setw(12) << "+-" << "+" << endl;
    cout << setfill(' ');
    cout << "| " << setw(15) << studentID << "| " << studentFirstName << " " << setw(23) << studentLastName << setw(4) << "| " << setw(4) << fixed << showpoint << setprecision(3) << studentPercent << setw(2) << "%" << "| " << setw(10) << studentGrade << "|" << endl;
    cout << setfill(' ');

    // reenter fstream values for row 3 
    readData >> studentID;
    readData >> studentFirstName;
    readData >> studentLastName;
    readData >> studentPercent;
    readData >> studentGrade;

    // change studentPercent from a decimal number to a percentage
    studentPercent = studentPercent * 100;

    // row 3 output
    cout << left;
    cout << setfill('-') << setw(17) << "+-" << setw(32) << "+-" << setw(12) << "+-" << setw(12) << "+-" << "+" << endl;
    cout << setfill(' ');
    cout << "| " << setw(15) << studentID << "| " << studentFirstName << " " << setw(20) << studentLastName << setw(4) << "| " << setw(4) << fixed << showpoint << setprecision(3) << studentPercent << setw(2) << "%" << "| " << setw(10) << studentGrade << "|" << endl;
    cout << setfill(' ');

    // reenter fstream values for row 4 
    readData >> studentID;
    readData >> studentFirstName;
    readData >> studentLastName;
    readData >> studentPercent;
    readData >> studentGrade;

    // change studentPercent from a decimal number to a percentage
    studentPercent = studentPercent * 100;

    // row 4 output
    cout << left;
    cout << setfill('-') << setw(17) << "+-" << setw(32) << "+-" << setw(12) << "+-" << setw(12) << "+-" << "+" << endl;
    cout << setfill(' ');
    cout << "| " << setw(15) << studentID << "| " << studentFirstName << " " << setw(23) << studentLastName << setw(4) << "| " << setw(4) << fixed << showpoint << setprecision(3) << studentPercent << setw(2) << "%" << "| " << setw(10) << studentGrade << "|" << endl;
    cout << setfill(' ');

    // reenter fstream values for row 5 
    readData >> studentID;
    readData >> studentFirstName;
    readData >> studentLastName;
    readData >> studentPercent;
    readData >> studentGrade;

    // change studentPercent from a decimal number to a percentage
    studentPercent = studentPercent * 100;

    // row 5 output
    cout << left;
    cout << setfill('-') << setw(17) << "+-" << setw(32) << "+-" << setw(12) << "+-" << setw(12) << "+-" << "+" << endl;
    cout << setfill(' ');
    cout << "| " << setw(15) << studentID << "| " << studentFirstName << " " << setw(22) << studentLastName << setw(4) << "| " << setw(4) << fixed << showpoint << setprecision(3) << studentPercent << setw(2) << "%" << "| " << setw(10) << studentGrade << "|" << endl;
    cout << setfill(' ');

    // reenter fstream values for row 6
    readData >> studentID;
    readData >> studentFirstName;
    readData >> studentLastName;
    readData >> studentPercent;
    readData >> studentGrade;

    // change studentPercent from a decimal number to a percentage
    studentPercent = studentPercent * 100;

    // row 6 output
    cout << left;
    cout << setfill('-') << setw(17) << "+-" << setw(32) << "+-" << setw(12) << "+-" << setw(12) << "+-" << "+" << endl;
    cout << setfill(' ');
    cout << "| " << setw(15) << studentID << "| " << studentFirstName << " " << setw(24) << studentLastName << setw(4) << "| " << setw(4) << fixed << showpoint << setprecision(3) << studentPercent << setw(2) << "%" << "| " << setw(10) << studentGrade << "|" << endl;
    cout << setfill('-') << setw(17) << "+-" << setw(32) << "+-" << setw(12) << "+-" << setw(12) << "+-" << "+" << endl;
    cout << setfill(' ');

    // close gradebook.txt file
    readData.close();


    return 0;
}