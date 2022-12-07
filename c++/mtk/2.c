#include <stdio.h>

int c;

int func(int n){
    c *= n;
    return n;
}

int main(void) {
	c = 1;
	int n = 2;
	func(func(func(func(func(func(func(func(n)))))))); 
	printf("c = %d\n", c); //c = 256
	return 0;
}