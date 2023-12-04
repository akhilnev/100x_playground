#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class complex{

    int a;
    int b;

    public:
        void setNumber(int n1 , int n2){
            a = n1;
            b = n2;
        }

    void printNumber(){
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }

    complex sumMe(complex o1, complex o2){
        complex o3;
        o3.setNumber((o1.a + o2.a), (o1.b + o2.b));
        return o3;
    } // Alternate way of doing the same sum 

    friend complex sumComplex(complex o1, complex o2); // friend function declaration


};


// sumComplex is allowed to do anything with private data of class complex
complex sumComplex(complex o1, complex o2){
    // can access provate data of both objects o1 and o2 as we have given a friend declaration!!!
    complex o3;
    o3.setNumber((o1.a + o2.a), (o1.b + o2.b));
    return o3;
}


int main(){

    complex c1, c2;
    c1.setNumber(1, 4);
    c2.setNumber(5,8);
    c1.printNumber();
    c2.printNumber();

    // Say we want to make c3 and store sum of C1 and C2 accordingly 
    complex c4 = c1.sumMe(c1,c2);
    c4.printNumber();
    complex c3 = sumComplex(c1, c2);
    c3.printNumber();

}