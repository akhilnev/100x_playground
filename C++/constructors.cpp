#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// Making constructors and destructors in C++ for automatic initialization and deallocation of objects

class Complex
{

    // ceating constructor
    int a, b;

public:
    Complex(void); 
    // constructor declaration ( needs to be public ) 
    //--> DEFAULT CONSTRUCTOR AS NO PARAMETERS ARE PASSED
    // automatically gets invoked when object is created
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

    Complex c1 , c2 , c3;

    c1.printData();
    c2.printData();
    c3.printData();

    return 0;
}