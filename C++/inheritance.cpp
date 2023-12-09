// Hybrid inheritance A-> B,C and B->D AND C->D ( mix of hierarchial and multiple inheritance)
// hierarchial inheritance A->B,C
// multiple inheritance B -> A and C -> A

#include <stdio.h>
#include <iostream>
using namespace std;


class Employee{
    
    public:

        int id;
        int salary;
        void setId(void){
            salary = 122;
            cout << "Enter the id of employee" << endl;
            cin >> id;
        }

        void getId(void){
            cout << "The id of this employee is " << id << endl;
        }

        Employee(int inpId){
            salary = 122;
            id = inpId;
        }

        Employee(){}; // make a default constructor as derived class will call this constructor and if not present, compile gives error

};


// Derived class syntax
// class {{derived-class-name}} : {{visibility-mode}} {{base-class-name}}

// DEFAULT VIBILITY MODE IS PRIVATE --> Base class public members become private members of derived class
// Say we set PUBLIC ---> Base class public members become public members of derived class
// IN NO CASE CAN WE INHERIT PRIVATE MEMBERS OF BASE CLASS

class Programmer : public Employee {


    int languageCode;

    public:

        Programmer(){
            salary = 122;
        }
        Programmer(int inpCode){
            id= inpCode;
        }
        void getLang(void){
            cout << "The language code of this employee is " << languageCode << endl;
        }

        void displaySalary(void){
            cout << "The salary of this employee is " << salary << endl;
        }

        void displayId(void){
            cout << "The id of this employee is " << id << endl;
        }
};



int main(){

    Programmer skillF(6);
    skillF.displayId();
    return 0;
}   