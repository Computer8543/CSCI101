// M05_Part_A_Lecture_Notes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// create a function to return the larger of two numbers
// int largerNum(int x, int y); // prototype 

// int x, y; // global variables 
/*
void largerNum(int x, int y)
{
    if (x > y)
        cout << x << " is larger " << endl;
    else
        cout << y << " is larger " << endl;
}

// default arguments
void largerNum(int x, int y = 50)
{
    if (x > y)
        cout << x << " is larger " << endl;
    else
        cout << y << " is larger " << endl;
}
*/
// void largerNum(int x, int y, int z); // function overloading
// void largerNum(int x, string y); //function overloading 

int main()
{
    /*
    int num;
    cout << "Enter a number " << endl;
    cin >> num;
    cout << "The square root is " << sqrt(num) << endl;

    

    
    cout << "The larger of x and y is " << largerNum(9, 12) << endl;
    
    int result;

    result = largerNum(100, 20) + 1000;

    cout << "The result is " << result << endl;
    */ 
    // with void function, the function can stand on its own
    // largerNum(100, 4);

    // default parameter for function
    // largerNum(100);

    return 0;
}
// function definition
/*
int largerNum(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}
*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
