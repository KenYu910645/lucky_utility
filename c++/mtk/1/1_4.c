// How to access array value via pointer
# include <stdio.h>
int main(){
    int a[10][20][30] = {0};
    a[5][2][1] = 2;
    
    printf("%d\n", *(*(*(a+5) +2) +1) ); // 2

    return 0;
}