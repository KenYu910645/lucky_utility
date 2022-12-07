#include <stdio.h>

int main(void) {
    int a[5] = {1,2,3,4,5};
    // int *p = (int *)(&a+1);
    printf("%d\n", *a); // 1
    printf("%d\n", &a); // 1482703616

    // ask: the value of *(a+1), (*p-1)?
}