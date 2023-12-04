#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Making constructors and destructors in C++ for automatic initialization and deallocation of objects

class Complex
{

    int a, b;

public:
    Complex(void); 
    // constructor declaration ( needs to be public ) 
    //--> DEFAULT CONSTRUCTOR AS NO PARAMETERS ARE PASSED
    // automatically gets invoked when object is created

    Complex(int a, int b); // --> PARAMETERIZED CONSTRUCTOR AS PARAMETERS ARE PASSED
    void printData()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};

Complex ::Complex(void) // --> DEFAULT CONSTRUCTOR AS NO PARAMETERS ARE PASSED
{
    a = 10;
    b = 0;
}

Complex :: Complex(int  a1 , int b1){
    a = a1;
    b = b1;
}


// Describing the parametrized constructore and defining it together inside the class
class Point{

    int x , y;

    public:
        Point(int a , int b){
            x = a ;
            y = b;
        }
        void displayPoint(){
            cout << "The point is (" << x << " , " << y << ")" << endl;
        }

        friend int pDistance(Point p1 , Point p2);
};


int pDistance(Point p1 , Point p2 ){
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y)); // easy just make a friend function to give internal access to the respective function outside the class
}

int main(int argc, char *argv[])
{

    Complex c1 , c2 , c3;

    Complex c(3,7); // --> PARAMETERIZED CONSTRUCTOR AS PARAMETERS ARE PASSED , NOTE NO NEW REQUIRED LIKE JAVA 

    c.printData();

    c1.printData();
    c2.printData();
    c3.printData();

    Point p(-1,-2);
    Point p2(1,2);
    p.displayPoint();
    cout << "The distance between the points is " << pDistance(p,p2) << endl;


    return 0;
}