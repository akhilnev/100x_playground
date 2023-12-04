#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class bank{

    int princ;
    int years;
    int interestRate;
    int returnValue;

    public:

     bank(){};
     bank(int p , int y , float r); // --> PARAMETERIZED CONSTRUCTOR, r = 0.4 form *** 
     bank(int p, int y , int r); // --> r = 40% 
     void show();

};

bank :: bank(int p , int y , float r){
    princ = p;
    years = y;
    interestRate = r;
    returnValue = princ;
    for(int i = 0 ; i < y ; i++){
        returnValue = returnValue * (1 + r);
    }
}

bank :: bank(int p ,int y , int r){
    princ = p;
    years = y;
    interestRate = r;
    returnValue = princ;
    for(int i = 0 ; i < y ; i++){
        returnValue = returnValue * (1 + float(r)/100);
    }
}

void bank :: show(){
    cout << "Principal amount was " << princ << ". Return value after " << years << " years is " << returnValue << endl;
}


int main(){
    bank bd1,bd2,bd3;// initialize all use blank constructor! 
    int p , y;
    int r ;
    float r2;

    cout << "Enter the value of p , y and r" << endl;
    cin >> p >> y >> r;
    bd1 = bank(p , y , r);
    bd1.show();
    r2 = ((float)r)/100;

    bd2 = bank(p , y , r2);    
    bd2.show();

    bd3.show();

    // BOTH GIVEN SAME VALUE BUT DIFFERENT CONSTRUCTORS ARE CALLED AT DYNAMIC TIME 
}






// different ways of initializing but same vaslue is given out 