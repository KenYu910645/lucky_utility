// What's the output of this program
# include <stdio.h>

int fun(int a, int* b){
    static int c = 0;
    a += *b;
    *b += a;
    c += a + *b;
    return c;
}

int main(){
    int x, y, z, sum;
    x = 5;
    y = 7;
    x = fun(x, &y);
    z = fun(x, &y);
    sum = x + y + z;
    printf("%d\n", sum); // 250
}