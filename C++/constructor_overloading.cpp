#include <stdio.h>
#include <iostream>
#include <string>


// OVERLOADING AND DEFAULT ARGUEMENTS CONSTRUCTORS !!!
// --> Constructors can be overloaded as well
// --> Constructors can also have default arguments
using namespace std;

class complex{

    int a;
    int b;

    public:

        // Clear overloading of constructors with different parameters, and different meanings 
        complex(int a, int b){
            this->a = a;
            this->b = b;
        } // Parameterized constructor
        

        complex(complex c1 , complex c2){
            a = c1.a + c2.a;
            b = c1.b + c2.b;
        }
        void setNumber(int n1 , int n2){
            a = n1;
            b = n2;
        }

    void printNumber(){
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }


};

int main(){

    complex c1(2,3);
    complex c2(3,4);
    complex c3(c1,c2);
    c3.printNumber();
}