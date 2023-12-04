#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// Forward Declaration
class complex;

class Calculator
{

public:
    int add(int a, int b)
    {
        return (a + b);
    }

    int sumReal(complex, complex);
    // --> we only declare it here and actually defined later in the code
    // we need to make it a friend class wth Calculator ka scope resolution operator --> we stoll get an error ?
    // give a forward ceclaration to tell Complex exists
    // Still error? --> Compiler does not know what are attribute in Complex yet so just declare method, define it later

    int CompComplex(complex, complex);
    // --> we only declare it here and actually defined later in the code
};

class complex
{

    int a;
    int b;

public:
    void setNumber(int n1, int n2)
    {
        a = n1;
        b = n2;
    }

    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }

    complex sumMe(complex o1, complex o2)
    {
        complex o3;
        o3.setNumber((o1.a + o2.a), (o1.b + o2.b));
        return o3;
    } // Alternate way of doing the same sum

    friend complex sumComplex(complex o1, complex o2); // friend function declaration

    friend int Calculator:: CompComplex(complex o1, complex o2); // friend function declaration

    friend int Calculator ::sumReal(complex o1, complex o2); // friend class declaration ( we need to make it a friend class wth Calculator ka scope resolution operator

    friend class Calculator; // friend class declaration ( we need to make it a friend class wth Calculator ka scope resolution operator
};

// sumComplex is allowed to do anything with private data of class complex
complex sumComplex(complex o1, complex o2)
{
    // can access provate data of both objects o1 and o2 as we have given a friend declaration!!!
    complex o3;
    o3.setNumber((o1.a + o2.a), (o1.b + o2.b));
    return o3;
}

// DEFINING THE METHOD HERE
int Calculator ::sumReal(complex o1, complex o2)
{
    return (o1.a + o2.a);
}

int Calculator :: CompComplex(complex o1, complex o2)
{
    return (o1.b + o2.b);
}



int main()
{

    complex c1, c2;
    c1.setNumber(1, 4);
    c2.setNumber(5, 8);

    Calculator calc;
    int res = calc.sumReal(c1, c2);
    cout << "The sum of real part of c1 and c2 is " << res << endl; // WORKS YAY!!!!
    int res2 = calc.CompComplex(c1, c2);
    cout << "The sum of complex part of c1 and c2 is " << res2 << "i" << endl; // WORKS YAY!!!!


// Say we have many more methods which we want to make friend of complex class
// WE MAKE A CLASS CALCULATOR AND MAKE IT A FRIEND OF COMPLEX CLASS --> GIVING IT ACCESS TO ALL PRIVATE DATA OF COMPLEX CLASS
// TO DO THAT WE DO: friend class Calculator; --> we need to make it a friend class wth Calculator ka scope resolution operator

}
