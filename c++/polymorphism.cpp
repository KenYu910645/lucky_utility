#include <iostream>
using namespace std;
/*
Reference: https://www.mygreatlearning.com/blog/polymorphism-in-cpp/
// The same function or class act differently according to different situation

Polymorphism 
1. Compile Time Polymorphism 
    * Function Overloading
    * Operator Overlaoding
2. Run Time Polymorphism
    * Function Overriding
    * Virtual function
*/

// Virtual function
// Abstract Class, this class can't be init
class Music {
    public:
        virtual void play() = 0; // pure virtual function, derived class MUST implement this interface
};
class ClassicalMusic: public Music {
    public:
        void play() override { // "overrider" is a reminder
            cout << "playing classical music" << endl;
        };
};
class PopMusic :  public Music{
    public:
        void play() override {
            cout << "playing Pop music" << endl;
        };
};

//Function Overriding
class Human {
    public:
        void makeLove(){
            cout << "Human making love" << endl; 
        }
};
class Girl: public Human {
    public:
        void makeLove(){
            cout << "Girl making love" << endl; 
        }
};

// Operator Overlaoding
class Num {
    public: 
        int val = 100;
        int operator+(Num);
};
int Num:: operator+(Num a)
    {return val + a.val;} 

// Function Overlaoding 
int sum(int x , int y){
    return x+y;
}
int sum(int x , int y, int z){
    return x+y+z;
}

int main(){

    // Function Overloading
    printf("%d\n", sum(1,2) ); // 3
    printf("%d\n", sum(1,2,3) ); // 6

    // Operator Overlaoding
    Num n1 = Num();
    Num n2 = Num();
    printf("%d\n", n1 + n2 ); // 200

    // Function Overriding 
    Human human = Human();
    human.makeLove();
    Girl girl = Girl();
    girl.makeLove();

    // Virtual function, define interface
    // Music music = Music(); // compiler error
    ClassicalMusic c_music = ClassicalMusic();
    c_music.play();
    PopMusic p_music = PopMusic();
    p_music.play();

    return 0;
}