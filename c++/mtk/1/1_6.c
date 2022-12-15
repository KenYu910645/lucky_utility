// What't the program output?
# include <stdio.h>
int main (){
    int i, j, m, n;
    i = 8;
    j = 10;
    m = ++i;
    n = j++;
    printf("%d, %d, %d, %d\n", i, j, m, n);// 9, 11, 9, 10
}