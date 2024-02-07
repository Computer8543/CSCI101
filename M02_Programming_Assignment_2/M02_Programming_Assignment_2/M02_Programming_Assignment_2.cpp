/* Program name: main.cpp
*  Author: Kyle Ingersoll
*  Date last updated: 9/1/2023
*  Purpose: The user enters 5 calendar events into the console, then the program calculates reminder dates for all of the events,
*           and finally outputs a table to a file with the event information in it.
*/
#include <iostream> // Manages console input and output
#include <fstream> // Manages file reading and writing
#include <string>  // Includes string data type
#include <iomanip> // Allows for manipulation of input and output

using namespace std; // Initializes standard namespace


int main() // Main function is where our code is supposed to be 
{
    // Declare variable data types
    string eventName;
    int eventMonth, eventDay, eventYear, reminderDay;

    // declare fstream variable for output
    ofstream outData;

    // associate fstream variables with file
    outData.open("events.txt");

    // Output File Table Heading
    /*output file*/ outData << left;
    /*output file*/ outData << "|" << setw(50) << setfill('-') << "-" << "|" << endl;
    /*output file*/ outData << setfill(' ');
    /*output file*/ outData << "| " << setw(19) << "Event Name" << "| " << setw(11) << "Event Date" << "| " << setw(15) << "Reminder Date" << "| " << endl;
    /*output file*/ outData << "|" << setw(50) << setfill('-') << "-" << "|" << endl;
    /*output file*/ outData << setfill(' ');

    // User prompt Block 1
    cout << "Enter the first event name: " << endl;
    getline(cin, eventName);
    cout << "Enter the month for the event as a number: " << endl;
    cin >> eventMonth;
    cout << "Enter the day for the event as a number: " << endl;
    cin >> eventDay;
    cout << "Enter the year for the event as a number: " << endl;
    cin >> eventYear;

    // Need to go through all characters to clear out newline before getline sees it and captures it
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    // Calculate reminderDay
    reminderDay = eventDay - 1;

    // Output File Table Row 2
    // note to self, if need to adjust width of cells to data size, change values of setw between eventDay and eventYear to affect Event Date, and change values of setw between reminderDay and eventYear to affect reminderDate.
    /*output file*/ outData << left;
    /*output file*/ outData << "|" << setw(50) << setfill('-') << "-" << "|" << endl;
    /*output file*/ outData << setfill(' ');
    /*output file*/ outData << "| " << setw(19) << eventName << "| " << eventMonth << "\\" << eventDay << "\\" << setw(5) << eventYear << "| " << eventMonth << "\\" << reminderDay << "\\" << setw(9) << eventYear << "| " << endl;
    /*output file*/ outData << "|" << setw(50) << setfill('-') << "-" << "|" << endl;
    /*output file*/ outData << setfill(' ');

    // User prompt Block 2
    cout << "Enter the second event name: " << endl;
    getline(cin, eventName);
    cout << "Enter the month for the event as a number: " << endl;
    cin >> eventMonth;
    cout << "Enter the day for the event as a number: " << endl;
    cin >> eventDay;
    cout << "Enter the year for the event as a number: " << endl;
    cin >> eventYear;

    // Need to go through all characters to clear out newline before getline sees it and captures it
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Calculate reminderDay
    reminderDay = eventDay - 1;

    // Output File Table Row 3
    /*output file*/ outData << left;
    /*output file*/ outData << "|" << setw(50) << setfill('-') << "-" << "|" << endl;
    /*output file*/ outData << setfill(' ');
    /*output file*/ outData << "| " << setw(19) << eventName << "| " << eventMonth << "\\" << eventDay << "\\" << setw(5) << eventYear << "| " << eventMonth << "\\" << reminderDay << "\\" << setw(9) << eventYear << "| " << endl;
    /*output file*/ outData << "|" << setw(50) << setfill('-') << "-" << "|" << endl;
    /*output file*/ outData << setfill(' ');


    // User prompt Block 3
    cout << "Enter the third event name: " << endl;
    getline(cin, eventName);
    cout << "Enter the month for the event as a number: " << endl;
    cin >> eventMonth;
    cout << "Enter the day for the event as a number: " << endl;
    cin >> eventDay;
    cout << "Enter the year for the event as a number: " << endl;
    cin >> eventYear;

    // Need to go through all characters to clear out newline before getline sees it and captures it
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Calculate reminderDay
    reminderDay = eventDay - 1;

    // Output File Table Row 4
    /*output file*/ outData << left;
    /*output file*/ outData << "|" << setw(50) << setfill('-') << "-" << "|" << endl;
    /*output file*/ outData << setfill(' ');
    /*output file*/ outData << "| " << setw(19) << eventName << "| " << eventMonth << "\\" << eventDay << "\\" << setw(5) << eventYear << "| " << eventMonth << "\\" << reminderDay << "\\" << setw(9) << eventYear << "| " << endl;
    /*output file*/ outData << "|" << setw(50) << setfill('-') << "-" << "|" << endl;
    /*output file*/ outData << setfill(' ');

    // User prompt Block 4
    cout << "Enter the fourth event name: " << endl;
    getline(cin, eventName);
    cout << "Enter the month for the event as a number: " << endl;
    cin >> eventMonth;
    cout << "Enter the day for the event as a number: " << endl;
    cin >> eventDay;
    cout << "Enter the year for the event as a number: " << endl;
    cin >> eventYear;

    // Need to go through all characters to clear out newline before getline sees it and captures it
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Calculate reminderDay
    reminderDay = eventDay - 1;

    // Output File Table Row 5
    /*output file*/ outData << left;
    /*output file*/ outData << "|" << setw(50) << setfill('-') << "-" << "|" << endl;
    /*output file*/ outData << setfill(' ');
    /*output file*/ outData << "| " << setw(19) << eventName << "| " << eventMonth << "\\" << eventDay << "\\" << setw(5) << eventYear << "| " << eventMonth << "\\" << reminderDay << "\\" << setw(9) << eventYear << "| " << endl;
    /*output file*/ outData << "|" << setw(50) << setfill('-') << "-" << "|" << endl;
    /*output file*/ outData << setfill(' ');

    // User prompt Block 5
    cout << "Enter the fifth event name: " << endl;
    getline(cin, eventName);
    cout << "Enter the month for the event as a number: " << endl;
    cin >> eventMonth;
    cout << "Enter the day for the event as a number: " << endl;
    cin >> eventDay;
    cout << "Enter the year for the event as a number: " << endl;
    cin >> eventYear;

    // Calculate reminderDay
    reminderDay = eventDay - 1;

    // Output File Table Row 6
    /*output file*/ outData << left;
    /*output file*/ outData << "|" << setw(50) << setfill('-') << "-" << "|" << endl;
    /*output file*/ outData << setfill(' ');
    /*output file*/ outData << "| " << setw(19) << eventName << "| " << eventMonth << "\\" << eventDay << "\\" << setw(5) << eventYear << "| " << eventMonth << "\\" << reminderDay << "\\" << setw(9) << eventYear << "| " << endl;
    /*output file*/ outData << "|" << setw(50) << setfill('-') << "-" << "|" << endl;
    /*output file*/ outData << setfill(' ');

    // close file
    outData.close();


    return 0;
}