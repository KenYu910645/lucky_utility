#include <stdio.h>

int main()
{
    // char array without '\0'
    char c1[] = {'a', 'p', 'p', 'l', 'e'};
    char c2[] = {'a', 'p', 'p', 'l', 'e', '\0'};
    printf("c1 = %s\n", c1); // 'appleapple' because no ending char
    printf("c2 = %s\n", c2);
    
    char c3[] = { 'h', 'a', 'p', 'p', 'y', '\0', 'w', 'i', 't', 'h', 'u', '\0'};
    printf("c3 = %s\n", c3); // 'happy'

    // Init char via "", system will add '\0' at the end 
    char c4[] = "hello";
    printf("%s\n", c4); // 'spiderkiller', %s will reach until it finds the '\0'
    printf("%c\n", c4[5]); // '\0'

	return 0;
}