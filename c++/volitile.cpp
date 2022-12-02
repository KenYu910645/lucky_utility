#include <iostream>     
using namespace std;

/*
Volatile prevent compile optimize its memory reading. 
Every time volatile variable is refered, system will go back to memory and read, instead of reading in register
This is good for variable that constantly changing, e.g., clock_tick or value that change during interrput
* For global variable that been change during interrupt 
* For global variable in multithreading



*/



int main()
{
    volatile int x = 0;
    cout << x << endl;
}





