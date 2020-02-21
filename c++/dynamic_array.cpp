#include <iostream>
#include <cstring>     
using namespace std; 

void print_array(int* a);

int main() { 

    int  Array1[5] = {1,2,3,4,5};
    int* Array2 = new int(5);

    //initialize Array2
    for (int i=0; i<5; i++)
    {
        Array2[i] = i+1;
    }
    cout << "Array1 = " ;
    print_array(Array1);
    cout << "Array2 = " ;
    print_array(Array2);

    delete Array2;
    return 0; 
}

void print_array(int* a)
{
    cout << '[';
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] <<" " ;
    }
    cout << ']' <<endl;
}