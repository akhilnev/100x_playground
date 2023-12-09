#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

//VIRTUAL BASE CLASS IN C++:
// --> A virtual base class is a class that is used as a base class for some other derived classes.
// --> It can be declared by preceding the class name with the keyword virtual.
// --> It is used in virtual inheritance, when a class inherits from more than one class, but wants only one copy of the base class.
// --> It is used to resolve ambiguity when a derived class inherits from two classes, and both the classes have a common base class.
// --> It is used to avoid the “diamond problem” of multiple inheritance.
class student{

    protected:
        int roll_number;

    public:
        void set_number(int a){
            roll_number = a;
        }

        void print_number(void){
            cout << "Your roll number is " << roll_number << endl;
        }
};

class test : virtual public student{

    protected:
        float maths, physics;

    public:
        void set_marks(float m1, float m2){
            maths = m1;
            physics = m2;
        }

        void print_marks(void){
            cout << "You result is here: " << endl
                 << "Maths: " << maths << endl
                 << "Physics: " << physics << endl;
        }
};

class sports : virtual public student{

    protected:
        float score;

    public:
        void set_score(float sc){
            score = sc;
        }

        void print_score(void){
            cout << "Your PT score is " << score << endl;
        }
};

class result : public test, public sports{

    private:
        float total;

    public:
        void display(void){
            total = maths + physics + score;
            print_number();
            print_marks();
            print_score();
            cout << "Your total score is " << total << endl;
        }
};

int main(){
    result anil;
    anil.set_number(420);
    anil.set_marks(78.9, 99.5);
    anil.set_score(9);
    anil.display();
    return 0;
}

