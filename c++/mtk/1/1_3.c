// what's the output of this program
# include <stdio.h>
# include <string.h>

int main(){
    char str[20] = "ABCDEF";
    printf("%d %d", sizeof(str), strlen(str)); // 20, 6
}