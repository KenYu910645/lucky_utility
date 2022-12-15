# include <stdio.h>
# include <string.h>

char src[] = "Hello World";
char dst[20];

int main()
{
    // printf("%d/n", sizeof(dst)); // 20

    strncpy(dst, src, sizeof(dst)); // copy string
    printf(":%zu:", strlen(dst));

    memcpy(dst, src, 5); // copy "Hello" to dst
    printf(":%zu:", strlen(dst));
    
    strncpy(dst, src, 5);   
    printf(":%zu:", strlen(dst));
    
    // Output is :11::11::11:
}