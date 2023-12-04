#include <iostream>
#include <string>

using namespace std; 

int sum (int a, int b); // function prototype

void swap(int a, int b){

    int temp = a;
    a = b;
    b = temp;

} // ALL LOCAL WRONG SWAP TO SWAP PASSED IN PARAMETERS - value copied in formal parameters

void swapPointer(int *a, int *b){
    
        int temp = *a;
        *a = *b;
        *b = temp;
    
    } //Pointer Swap valid in C too !


// Call by refference using refference Variables - C++ Specific !!
void swapReference(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int &swapRefRet(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
    return a;
}

int main() {

string s1;
string s2;
cin >> s1 >> s2;
cout << s1 << " " << s2 << endl;
int a = 4;
int b = 5;

swap(a,b); // wont work or call by value

cout << a << " " << b << endl;

swapPointer(&a,&b); // works or call by refference using pointers

swapReference(a,b); // works or call by refference using refference variables - C++ Specific !!

swapRefRet(a,b) = 686; // sets a to 686 , swaps b to old a value, magic of a poiniter !!

cout << a << " " << b << endl;

int x = 10;

int y = 30;

cout << swapRefRet(x,y); // should return x with the value of 30 and swap y to 10 


}





int sum(int a, int b) {
    return a+b;
}


