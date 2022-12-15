// What is the output of this program

# include <stdio.h>

int funcA(int &a, int b){
    a = (a%7 == 0)?(a/7):(a%7);
    b = (b%17 == 0)?(b/17):(b%17);
    return a+b;
}

int main(){
    int a = 41;
    int b = 61;
    int c = funcA(a, b);

    printf("%d %d\n", a, c); // 6 16
    return 0;
}