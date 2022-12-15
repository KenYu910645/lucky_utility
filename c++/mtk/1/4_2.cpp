// What's the print out result? 
# include <iostream>
using namespace std;

class A{
    public: 
        virtual void func(int val = 1) {printf("func A\n");}
        virtual void test() {func();}
};

class B: public A{
    public:
        void func(int val = 0) {printf("func B\n");}
};

int main (){
    B *p = new B;
    p->test(); // func B
    return 0;
}