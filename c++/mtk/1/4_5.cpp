// What's the output of this program?

# include <iostream>
using namespace std;

class Parent{
    public: 
        Parent(){};
        virtual ~Parent() { cout << "Destructor Parent" << endl;}
        virtual void fn() { cout << "Call Parent fn" << endl;}
};
class Child: public Parent{
    public:
        ~Child(){ cout << "Destructor Child" << endl; }
        virtual void fn() {cout << "Call Child fn" << endl;}
};

void test(Parent &obj){
    obj.fn();
}

int main(){
    Parent obj1;
    Child obj2;
    Parent* obj3 = new Child;
    test(obj1); // Call Parent fn
    test(obj2); // Call Child fn
    test(*obj3); // Call Child fn
    delete obj3; // Destructor Child
                 // Destructor Parent
    // Implicitly destory obj2: Destructor Child
    //                          Destructor Parent
    // Implicitly destory obj3: Destructor Parent
    return 0;
}