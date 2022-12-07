#include <iostream>     
using namespace std; 
/*
Tips: Read from right to left and * represent "pointing to"

int a; // 一個整型數
int *a; // 一個指向整數的指標
int **a; // 一個指向指標的指標，它指向的指標是指向一個整型數
int a[10]; // 一個有10個整數型的陣列
int *a[10]; // 一個有10個指標的陣列，該指標是指向一個整數型的
int (*a)[10]; // 一個指向有10個整數型陣列的指標
int (*a)(int); // 一個指向函數的指標，該函數有一個整數型參數並返回一個整數
int (*a[10])(int); // 一個有10個指標的陣列，該指標指向一個函數，該函數有一個整數型參數並返回一個整數

const int * foo; // 一個 pointer，指向 const int 變數。
int const * foo; // 一個 pointer，指向 const int 變數。
int * const foo; // 一個 const pointer，指向 int 變數。
int const * const foo; // 一個 const pointer，指向 const int 變數。
*/

void print_address_and_value(int* a);

int main() 
{   
    cout << "=======================" << endl;
    cout << "*pointer means get the value of the pointer points at" << endl;
    cout << "&value means get the pointer of that value" << endl;
    int x = 0;
    cout << "int x = 0" << endl;
    cout << "&x = " << &x << endl;
    cout << "*&x = " << *&x << endl;
    
    cout << "=======================" << endl;
    cout << "use int* to declare a pointer that points to interger variable";
    cout << "int* x_ptr = &x;" << endl;
    int* x_ptr = &x;
    cout << "x_ptr = " << x_ptr << endl;
    cout << "=======================" << endl;


    int Array[5] = {1,2,3,4,5}; // sizeof(int) = 4 byte

    cout << "int Array[5] = {1,2,3,4,5}" << endl;
    print_address_and_value(Array);

    cout << "=======================" << endl;
    cout << "Array = "    << Array    << endl; // get pointer pointing to A[0]
    cout << "*Array = "   << *Array   << endl; // get value of A[0]
    cout << "Array[0] = " << Array[0] << endl; // get value from A[0]
    cout << "=======================" << endl;
    cout << "Array + 1 = "   << Array + 1  << endl;
    cout << "*(Array + 1) = " << *(Array + 1) << endl; // get value
    cout << "=======================" << endl;
    cout << "(&Array[1]) + 1 = "   << (&Array[1]) + 1 << endl; 
    cout << "*((&Array[1]) + 1) = " << *((&Array[1]) + 1)<< endl; // get value
    return 0; 
}

void print_address_and_value(int* a)
{
    for (int i=0;i<5;i++)
    {
        cout << "Address = " << &(a[i]) << ", value = " << a[i] << endl ;
    }
}