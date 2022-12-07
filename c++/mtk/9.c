#include <stdio.h>

void f0(void){;};
void f1(void){;};
void f2(void){;};
void f3(void){;};
void f4(void){;};

int main(){

    int n = 3;

    // Declare an array with 5 function pointers
    void (*p[5])(void);
    p[0] = &f0;
    p[1] = &f1;
    p[2] = &f2;
    p[3] = &f3;
    p[4] = &f4;

    //
    p[n]();

    return 0;
}