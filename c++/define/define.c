#include <stdio.h>

#define PI 3.1415926    //常數巨集
#define MIN(A, B)  ( (A) <= (B) ? (A) : (B) ) //函數巨集
#define SUM(a, b)  ( a+b )

/* 引入防護 (Include guard) 是一種條件編譯，用於防範 #include 指令重複引入的問題*/
/* 若前處理器已經 define MYHEADER，就編譯 part A，否則編譯 part B。 */
#ifdef MYHEADER
#define MYHEADER
   // part A
#else
   // part B
#endif

#define DEBUG // enable debugging flag

#if !defined(__cplusplus)
    #error C++ compiler required.
#endif


int main()
{
    /* DEBUG flag */
    
    #ifdef DEBUG
        printf("Enable debugging\n");
    #endif

    printf("Hello World\n");

    printf("%f\n", PI*10);

    printf("%d\n", MIN(100, 101));

    printf("%d\n", SUM(100, 101));

    // int i = 1;
    // i < 0 ? printf("i is below 0\n") : printf("i is over or equal to 0\n");


    return 0;
}

