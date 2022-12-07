#include <iostream>
using namespace std;

// Reference
// http://ot-note.logdown.com/posts/178610/global-and-static-variables

// Static variables have a lifetime equal to the program's lifetime, 
// but they still follow scoping rules based on where they are declared.
// static member function can change static variable that declare in that class 

extern int global_var; // allow static_1.cpp access global variabel define in other files
// extern int static_var; // Can't access static variable because it's declare in other file

int x = 123; // global variable

// We can use static variable to count how many time the function invoke
void func() {
   static int counter = 0; // statics variable only be init once
   counter++;
   cout << "count of calling func() = " << counter << endl;
   cout << "x in func() = " << x << endl; // correct global variable
}

int main()
{
    cout << "=======================" << endl;
    cout << "global_var = " << global_var << endl;
    // cout << "static_var = " << static_var << endl; 

    int x = 456; // local_var override global_var 
    cout << "x in main() = " << x << endl; // overrided 
    
    // Testing static variable in function 
    cout << "=======================" << endl;
    func();
    func();
    func();
    return 0; 
}