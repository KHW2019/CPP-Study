#include <iostream>
using namespace std;

int InputSize;
int i;

int* PrintNumberList(){
    for (i = 0; i < InputSize; i++) {
        if (i % 15 == 0)
            cout << "Fizz Buzz,\t";
        else if ((i % 3) == 0)
            cout << "Fizz,\t";
        else if ((i % 5) == 0)
            cout << "Buzz,\t";
        else
            cout << i << ",\t";
    }
    return 0;
}
int main()

{
    cout << "Please Enter a number : ";
    cin >> InputSize;
    PrintNumberList();
}
