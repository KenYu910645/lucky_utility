#include <iostream>     
using namespace std; 


//Declare an adding function
int func1(int x1, int x2){
    return x1 + x2;
}
//Declare a minor function
int func2(int x1, int x2){
    return x1 - x2;
}

//Declare a function
bool func_is_bigger(int x1, int x2){
    return x1 >= x2;
}
//Declare a function
bool func_is_smaller(int x1, int x2){
    return x1 <  x2;
}

void sort_two_number(int x1, int x2, bool (*cmp)(int, int)) {
    if ( cmp(x1, x2) ) {
        cout << x1 << ", " << x2 << endl;
    }
    else
        cout << x2 << ", " << x1 << endl;
}



int main() 
{   
    cout << "=======================" << endl;

    // Declare a function pointer
    int (*func_ptr)(int, int);
    cout << "func_ptr = " << func_ptr << endl;
    
    // Assign func1 to function pointer
    func_ptr = &func1;
    cout << "func_ptr = " << func_ptr << endl;

    // Directly execute via func_ptr
    cout << "func_ptr(1,2) = " << func_ptr(1,2) << endl;

    // Assign func2 to function pointer
    func_ptr = &func2;
    cout << "func_ptr = " << func_ptr << endl;

    // Directly execute via func_ptr
    cout << "func_ptr(1,2) = " << func_ptr(1,2) << endl;

    cout << "=======================" << endl;
    
    
    // Declare a function pointer for sorting function
    bool (*func_cmp_ptr)(int, int);
    
    //sort decendent
    func_cmp_ptr = &func_is_bigger;
    cout << "sort decendently: " << endl;
    sort_two_number(1, 2, func_cmp_ptr);

    //sort asendent
    func_cmp_ptr = &func_is_smaller;
    cout << "sort asendently: " << endl;
    sort_two_number(1, 2, func_cmp_ptr);
    
    return 0; 
}
