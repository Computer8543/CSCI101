// C_Plus_Plus_Hello_World.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string> 
using namespace std;

int main()
{
    std::cout << "Hello World!\n";
    std::cout << "I am learning c++ code" << endl;

    // declare a variable for age
    int age;
    // declare and initialize
    int yourage = 12;

    age = 25;
    age = 30;
    cout <<"I am " << age << " years old" << endl;
    int combinedAge;
    combinedAge = yourage + age;
    cout << "Our combined age is " << combinedAge << endl;
    // Alternatively:
    cout << "Combined age is " << yourage + age << endl;

    // input from user with cin
    int futureAge;
    cout << "Enter your age " << endl;
    cin >> yourage;
    futureAge = yourage + 100;
    cout << "Your future age is " << futureAge << endl;

    // declare a string variable
    string username;
    cout << "Enter your username" << endl;
    cin >> username;
    cout << username << ", you have been denied access" << endl;
    int x, y;
    x = 5;
    y = x++;


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
