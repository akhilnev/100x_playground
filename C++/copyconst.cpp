#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;



//WHAT IS COPY CONSTRUCTORS ???


class Number{

    int a;

    public:
        Number(){
            a = 0;
        }

        Number(int num){
            a = num;
        }

        // When no copy constructor is found, compiler supplies its own copy constructor
        Number(Number &obj){
            cout << "Copy constructor called!!!" << endl;
            a = obj.a;
        }

        void display(){
            cout << "The number for this object is " << a << endl;
        }

       
};

int main(){

    Number x,y,z(45),z3;
  
    Number z1(z); // Copy constructor invoked   // --> Copy constructor is a constructor which initializes an object using another object of the same class
    // NOTE THIS IS A SHALLOW COPY CONSTRUCTOR AS Z1 AND Z ARE NOT INDEPENDENT !! SAME MEMORY LOCATION IS USED FOR BOTH !!

    
    // NOTE COPY CONSTRUCTOR IS ALSO PRESENT AS DEFAUL IN COMPILER AND IS USED WHEN COMPILER IS NOT ABLE TO FIND A COPY CONSTRUCTOR

    z1.display();

    z3 = y; // copy constructor NOT called here !!!
    z3.display();

    Number z2 = z; // copy constructor CALLED HERE !!! ---> DEEP COPY CONSTRUCTOR , Z2 AND Z ARE INDEPENDENT !!
    z2.display();

}
