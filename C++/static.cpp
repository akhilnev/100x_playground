#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Employee{
    int id;
    static int count; // static variable --> We need to define it here 
    // count is the static data  member of class Employee --> it is shared by all objects of class Employee
    public:
        void setData(void){
            cout << "Enter the id" << endl;
            cin >> id;
            count++;
        }
        void getData(void){
            cout << "The id of this employee is " << id << " and this is employee number " << count << endl;
        }
        
        // Making a Static Function. What is a static function? Why do we need it?
        // A static member function can only access static data member, other static member functions and any other functions from outside the class.
        
        static void getCount(void){ // static function ---> this is a static member function --> only access stati
            // cout << id; // throws error as cannot access non static member from static function
            cout << "The value of count is " << count << endl;
        }
};


int Employee :: count = 0 ; // default value is 0, so dont need to ideally initialize  --> we need to write it here as memory is allocated based on full class not individual objects object 

int main(){

    Employee harry, rohan, lovish;
    // harry.id = 1;
    // harry.count = 1; // cannot do this as id and count are private
    harry.setData();
    harry.getData();
    Employee :: getCount(); // can call static function using class name --> call static variable based on class name *** 
    rohan.setData();
    rohan.getData();
    Employee :: getCount();
    lovish.setData();
    lovish.getData();
    Employee :: getCount();

};