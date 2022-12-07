# include <stdio.h>
# include <string.h>

char src[] = "Hello World";
char dst[20];

int main()
{
    strncpy(dst, src, sizeof(dst));
    printf(":%zu", strlen(dst));

    memcpy(dst, src, 5);
    printf(":%zu", strlen(dst));
    
    strncpy(dst, src, 5);   
    printf(":%zu", strlen(dst));
    
}