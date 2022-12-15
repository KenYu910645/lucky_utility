// Will executing the program cause ambiguity?
// Ans: Yes! the compiler will complain "error: reference to ‘out’ is ambiguous"
// Reference: https://openhome.cc/Gossip/CppGossip/MultiInheritance1.html
# include <iostream>
using namespace std;

class A {
    public:
        void out() {cout << "A";}
};
class B {
    public:
        void out() {cout << "B";}
};
class C: public A, public B {
    public:
        void print() {out();} // Both A, B class has the same member function, causing ambiguity
};
int main (){
    C c;
    c.print();

    return 0;
}