#include <iostream>     
using namespace std; 

void print_address_and_value(int* a);



int main() 
{
    int Array[5] = {1,2,3,4,5}; // sizeof(int) = 4 byte

    cout << "int Array[5] = {1,2,d3,4,5}" << endl;
    print_address_and_value(Array);
    cout << "=======================" << endl;
    cout << "Array = "    << Array    << endl; // get pointer pointing to A[0]
    cout << "*Array = "   << *Array   << endl; // get value of A[0]
    cout << "Array[0] = " << Array[0] << endl; // get value from A[0]
    cout << "=======================" << endl;
    cout << "Array + 1 = "   << Array+1  << endl; 
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
        cout << &(a[i]) << " " << a[i] << endl ;
    }
}