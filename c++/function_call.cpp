#include <iostream>     
using namespace std; 

/* Note that C++ only implement "call by value"
   but user can implement "call by reference" by passing a pointer to a function
*/

void func1(int x){ // call by value
    x++;
    cout << "In func1, x = " <<  x << endl;
}

void func2(int *x){ // call by address
    (*x)++;
    cout << "In func1, *x = " <<  *x << endl;
}

void func3(int &x){  // call by reference
    x++;
    cout << "In func1, x = " <<  x << endl;
}

int main()
{
    cout << "=========== call by value ======== " << endl;
    int x1 = 0;
    func1(x1);
    cout << "x1 after func1 = " << x1 << endl;

    cout << "=========== call by address ======== " << endl;
    int x2 = 0;
    func2(&x2);
    cout << "x2 after func2 = " << x2 << endl;

    cout << "=========== call by reference ======== " << endl;
    int x3 = 0;
    func3(x3);
    cout << "x3 after func3 = " << x3 << endl;

    return 0; 
}
