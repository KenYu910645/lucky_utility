# include <stdio.h>
# include <string.h>
// char src[] = "Hello World";
// char dst[20];

int main()
{
    char str[20] = "ABCDEF";
    printf("%d %d", sizeof(str), strlen(str));
}