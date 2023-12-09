// SPECIFIC TO C++ - NOT IN JAVA - LEADS TO VIRTUAL FUNCTIONS -> IMPORTANT FOR THE FINALS AND IN GENERAL 
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Base1{

    int base1int;

    public:

    Base1(){
        cout << "Default constructor of base1 class called" << endl;
    }

    Base1(int a){
        base1int = a;   
    }
        void greet(){
            cout << "How are you ?" << endl;
        }
};


class Base2{

    int base2int;

    public:

    Base2(){
        cout << "Default constructor of base2 class called" << endl;
    }

    Base2(int a){
        base2int = a;   
    }
        void greet(){
            cout << "Kaise ho ?" << endl;
        }
};

class Derived : public Base1, public Base2{


    int derived1, derived2;

    public:

    Derived(int a, int b) : Base1(a), Base2(b) {
    }// What syntax is this ? ---> This is called initialization list which is used to initialize data members of the base class

    Derived(int a, int b, int c, int d) : Base1(a), Base2(b) {
        derived1 = c;
        derived2 = d;
    }

    Derived(void): Base1(), Base2(){
        derived1=0;
        derived2=0;
    }

    void greet(){ // ---> AMBIGUITY PROBLEM using Ovveriding
        //Base1 :: greet(); // ---> AMBIGUITY RESOLVED another way using scope resolution operator
        cout << "How are you doing ?" << endl;
    }
};




int main(){

    Derived harry(1,2);
    harry.greet();
    Derived h1;

    return 0;
}
