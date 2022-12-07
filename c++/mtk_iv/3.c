# include <stdio.h>
int count =0 ;
int c(int x){
    count++;
    return x > 0 ? c(x-1) + c(x-2) +1 :1;
}

int main(){
    int result = c(5);
    printf("%d %d\n", result, count);
    return 0;
}