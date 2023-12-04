#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Complex
{


    int a, b;

public:
    Complex(void); // DEFAULT CONSTRUCTOR 

    void printData()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};

Complex ::Complex(void)
{
    a = 10;
    b = 0;
}

int main(int argc, char *argv[])
{


    return 0;
}