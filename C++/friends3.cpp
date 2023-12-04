#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Y; // Forward Declaration

class X{

    int data;

    public:

    void setData(int value){
        data = value;
    }

    friend void add(X, Y); // Compiler does not know what are attribute in Y yet so just declare method, define it later
};

class Y{

 int num;

    public:

    void setData(int value){
        num = value;
    
}

    friend void add(X, Y);

};

void add(X o1, Y o2){
    cout << "Summing data of X and Y objects gives me " << (o1.data + o2.num);
}


int main(){

    X a;
    Y b;
    a.setData(4);
    b.setData(5);
    add(a,b);
    return 0;
};

