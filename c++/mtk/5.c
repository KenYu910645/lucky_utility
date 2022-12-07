#include <stdio.h>
#define VAR 6

int func(int a){
    int m = 3;
#ifndef VAR
#define VAR 10
    m = 4;
#endif
    return m + VAR;
}

int main(void) {
	int i = 5;
	printf("%d\n", func(i)); // 9
	return 0;
}