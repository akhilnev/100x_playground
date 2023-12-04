#include <stdio.h>
#include <iostream>
#include <string>

// STRUCTURE VS CLASS
// ALL MEMEBERS OF STRUCTURE ARE PUBLIC BY DEFAULT, BUT IN CLASS THEY ARE PRIVATE BY DEFAULT ( VERY IMPORTANT FOR SECURITY)
// WE CAN ADD FUNCTIONS INSIDE A CLASS BUT NOT IN A STRUCTURE
// NO SECURITY CONCERN USE STRUCTURE ELSE CLASS

typedef struct Student
{

} St;

using namespace std;
class Employee
{

private:
    int a;
    int b;

public:
    int c;
    int d;
    void setData(int a, int b);
    void getData(); // can implement outside class using :: operator or here
};

void Employee ::setData(int a1, int b1)
{
    a = a1;
    b = b1;
}

void Employee ::getData()
{
    cout << "a = " << a << " b = " << b << endl;
} // can implement outside class using :: operator or here

class binary
{

    string s; // AUTO PRIVATE DECLARED
public:
    void read(void);
    void chk_bin(void);
};

void binary ::chk_bin(void)
{
    cout << "Enter a binary number" << endl;
    cin >> s; // take s into cin
    // how to check for binary ?
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != 0 && s.at(i) != 1)
        {
            cout << "Incorrect Binary Format" << endl;
            exit(0);
        } // in java it is charAt[i]
    }
    cout << "Correct Binary Format" << endl;
}

void binary:: read(void){
    chk_bin(); // this is an example of nested function, we can call it w/o object , ( this.chk_bin())
    cout << "Enter a binary number" << endl;
    cin >> s; // take s into cin
}

int main()
{

    Employee e1;
    e1.c = 10;
    e1.d = 20;
    e1.setData(1, 2);
    e1.getData();
    binary b;
    b.chk_bin();
    // note private varibale is auto accesible by all methods of class
    return 0;
}
