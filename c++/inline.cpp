#include <iostream>
using namespace std;

/*
Inline function tell compiler to copy-paste function segment when you call the function 
instead of actually calling the fucntion

This is good for very small fucntion that will be called many time, save time
*/

inline int func(int x){
    x++;    
    return x;
}

int main()
{
    int x = 0;    
    for (int i = 0 ; i < 10; i++){
        x = func(x);
    }
    cout << x << endl;
}
