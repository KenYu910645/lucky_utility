# include <stdio.h>
int count =0;

int calc(int x){
    count++;
    return x > 0 ? calc(x-1) + calc(x-2) + 1 : 1;
}

int main(){
    int result = calc(5);
    printf("%d,%d\n", result, count); // 25,25
    return 0;
}