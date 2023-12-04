#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// IN C++ ALL COMMON FUNCTIONS HAVE SAME MEMORY ALLOCATION TO BE EFFICIENT
// HOW to use arrays inside C++

class Shop{

    int itemId[100];
    int itemPrice[100];
    int counter;

    public:
        void intitCounter(void){counter = 0;}
        void displayPrice(void);
        void setPrice(void);
};

void Shop :: setPrice(void){
    cout << "Enter Id of your item no " << counter + 1 << endl;
    cin >> itemId[counter];
    cout << "Enter Price of your item" << endl;
    cin >> itemPrice[counter];
    counter++;
}

void Shop :: displayPrice(void){
    for (int i = 0; i < counter; i++)
    {
        cout << "The price of item with id " << itemId[i] << " is " << itemPrice[i] << endl;
    }
    
}

int main(){

    Shop dukan;
    dukan.intitCounter();
    dukan.setPrice();   
    dukan.setPrice();
    dukan.setPrice();
    dukan.displayPrice();

    // WHERE IS MEMORY ALLOCATED FOR ARRAYS HERE, DONT WE NEED TO MALLOC WHEN INITIALIZING ARRAYS ?
    // NO, C++ DOES IT FOR US, IT ALLOCATES MEMORY ON STACK, NOT HEAP, SO NO NEED TO FREE IT!

    // BUT WHAT IF WE WANT TO ALLOCATE MEMORY ON HEAP, WE CAN DO IT USING POINTERS !!
    // int *ptr = new int[34]; // 34 * 4 bytes allocated on heap
    // delete [] ptr; // free memory on heap

    // how do we know when to use stack or heap ?
    // if we want to allocate memory for a short time, use stack, else use heap
    
    // so if we are working on a huge programming project is it better to use heap ?
    // NO, HEAP IS SLOWER THAN STACK, SO USE HEAP ONLY WHEN NEEDED
};