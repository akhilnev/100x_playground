#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


// DESTUCTORS IN C++:
// --> A destructor is a member function which destructs or deletes an object.
// NEVER TAKES AN ARGUEMENT NOR TAKES A VALUE 

int count = 0 ;

class num{
    

    public:
        num(){
            count++;
            cout << "Constructor " << count << "called" << endl;

        }

        ~num(){
            cout << "Destructor" << count << "called" << endl;
             count--;
        }
};





int main(){

    num n1;

    {

        cout << "Creating 2 more objects" << endl;

        num n2,n3;

    // ALL OBJECTS INSIDE BLOCK ARE DELETED WHEN BLOCK ENDS !! 
    };

    // FREES ALL DYNAMICALLY ALLOCATED MEMORY !!
return 0;

};