#include <stdio.h>

#define INC(x) x+1

int n;
static int x;

int main(){
    printf("%d\n", n); // undefined behavior
    printf("%d\n", x); // undefined behavior
    
    int m; 
    printf("%d\n", x); // undefined behavior
    
    // for(i=0,j=1;i<5;i++)
    INC(3);
    
    return 0;
}
