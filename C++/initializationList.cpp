// Syntax :

// constructor (arguement list) : initialization-section 

#include <iostream>
using namespace std;
class Test
{
    int a;
    int b;
    public:
        // Test(int i, int j) : a(i), b(j) { }

        Test(void) :  b(0) { }
        Test(int i, int j) : a(i), b(i+j) { }
        void print() { cout << "a = " << a << " b = " << b << endl; }

};





int main(){

Test t;
t.print();
string s = "abc";
s[1] = 'd';
cout << s[3] << endl;


    return 0;
}



