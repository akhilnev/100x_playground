
#include <stdio.h>
#include <iostream>
using namespace std;

// SINGLE INHERITANCE : ONE BASE CLASS AND ONE DERIVED CLASS

// SIMPLE EXAMPLE LIKE BEFORE SHOWING WE CANNOT ACCESS PRIVATE MEMBERS OF BASE CLASS IN DERIVED CLASS
// BUT WE CAN ACCESS THEM USING PUBLIC MEMBER FUNCTIONS OF BASE CLASS ( LIKE JAVA BASICALLY )

class Base{
    int data1; // private by default and is not inheritable
    public:
        int data2;
        void setData(void);
        int getData1(void);
        int getData2(void);
};

class Derived : public Base { // Class is being derived publically
    // all public is inherited as public as public display is used !! 
    int data3;
    public:
        void process(void);
        void display(void);
};


void Base :: setData(void){
    data1 = 10;
    data2 = 20;
}

int Base :: getData1(void){
    return data1;
}

int Base :: getData2(void){
    return data2;
}

void Derived :: process(void){
    data3 = data2 * getData1();
}

void Derived :: display(void){
   // cout << "Value of data 1 is " << data1 << endl;// ---> derived class cannot access private members of base class
    cout << "Value of data 1 is " << getData1() << endl;
    cout << "Value of data 2 is " << data2 << endl;
    cout << "Value of data 3 is " << data3 << endl;
}



int main(){

    Derived der;    
    der.setData();
    der.process();
    der.display();

}