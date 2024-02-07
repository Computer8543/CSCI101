// FormatOutput.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip> // library to manipulate output 
#include <cmath>
#include <fstream> // allows reading from and writing to files 
#include <string>
using namespace std;

int main()
{
    /*
    double hours, pay;
    double rate = 15.755;
    

    cout << "Enter your hours " << endl;
    cin >> hours;

    pay = hours * rate;

    cout << fixed << setprecision(2); // use to set output to 2 decimal places 
    cout << pay; 

 

    const double PI = 3.14159265;

    double radius = 12.5;
    double height = 10.00;

    cout << fixed << showpoint; // forces the display of trailing 0 after decimal point

    cout << setprecision(2) << height << endl;

    // calculate the circumference and area of a circle and display the results to 2 decimal places.

    double circumference, area;

    circumference = 2 * PI * radius;
    area = PI * pow(radius, 2);

    cout << fixed << showpoint;

    cout << setprecision(2) << "The circumference of the circle is: " << circumference << endl;
    cout << setprecision(2) << "The area of the circle is: " << area << endl;
    
    //setw
    int miles = 245; 
    int speed = 55;
    double hours = 35.45;
    
    cout << right;

    cout << "Miles" << setw(10) << miles << endl;

    cout << "Speed" << setw(10) << speed << endl;
    

    // Using getline to capture strings with whitespaces.
    // getline (cin,variable)

    string phrase;

    cout << "Enter a catchy phrase: " << endl;
    // cin >> phrase;
    getline(cin, phrase);

    cout << phrase; 
    */
    string studentName;
    int age; 
    // declare fstream variable for input and output
    ifstream readData; // this functions like cin
    ofstream outData; // this functions like cout 

    // associate fstream variables with file
    readData.open("students.txt");
    readData >> studentName;
    readData >> age;
    int newAge = age + 10;
    outData.open("records.txt");
    outData << studentName << "/t" << newAge << endl;
    cout << studentName << " you are " << age;
    
    readData.close();
    outData.close();
        
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
