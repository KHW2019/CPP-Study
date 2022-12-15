// FirstCPPApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int x, y;
string equation;
int answer;

int addition() { answer = x + y; return answer; }

int subtraction() { answer = x - y; return answer; }

int multiplication() { answer = x * y; return answer; }

int division() { answer = x / y; return answer; }

void CheckEquation() {
    if (equation == "addition") {
        addition();
        cout << answer;
    }
    else if (equation == "subtraction") {
        subtraction();
        cout << answer;
    }
    else if (equation == "multiplication") {
        multiplication();
        cout << answer;
    }
    else if (equation == "division") {
        division();
        cout << answer;
    }
    else {
        cout << "Your entered equation does not match to with the options we provide";
    }
}

int main()
{
    cout << "Please enter your x value: ";
    cin >> x;
    cout << "Please enter your y value: ";
    cin >> y;
    cout << "Please Enter which type of equation you want to apply to value x and y. \n";
    cout << "Options are addition, subtraction, multiplication, division : ";
    cin >> equation;
    CheckEquation();
}