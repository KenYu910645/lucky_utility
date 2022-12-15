# include <stdio.h>
# define INC(x) x*=2;x+=1

int main(){
    int i, j;
    for (i = 0, j = 1; i < 5; ++i)
    INC(j);
    printf("%d\n", j); // 33

    return 0;
}