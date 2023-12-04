#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


class complex{

    int a;
    int b;
public:
        void setData(int v1, int v2){
                a = v1;
                b = v2;

        }

        void setDatabySum(complex o1, complex o2){
            a = o1.a + o2.a;
            b = o1.b + o2.b;
        }

        void printNumber(){
            cout << "Your complex number is " << a << " + " << b << "i" << endl;
        }

// creating a friend function
};

class Employee{

    int id;
    int salary;

    public:
        void setId(void){
            salary = 122; // all employees will have same salary
            cout << "Enter the id of employee" << endl;
            cin >> id;
        }
        void getId(void){
            cout << "The id of this employee is " << id << endl;
        }

};


int main(){

    Employee fb[4]; // 4 employee objects are created in array but none of them are initialized yet we need to do that befoere using them ( in Java we do = new Complex(...) based on constructor we have created)
    for (int i = 0; i < 4; i++)
    {
        fb[i].setId();
        fb[i].getId();
    }

     complex c1, c2, c3;
        c1.setData(1, 2); 
        c1.printNumber(); 
        c2.setData(3, 4);
        c2.printNumber();
        c3.setDatabySum(c1, c2); // Pass in same class objects to add a values and b values separately and store in c3
        c3.printNumber();



}