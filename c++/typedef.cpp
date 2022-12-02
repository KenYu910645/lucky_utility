#include <iostream>     
using namespace std; 

int main() 
{   
    cout << "=======================" << endl;

    // define int to tow different self-defined type
    // this can make your variable more unstandable
    typedef int NegativeNumber;
    typedef int PositiveNumber;

    NegativeNumber neg;
    PositiveNumber pos;

    neg = -1;
    pos =  1;

    neg = pos;

}
