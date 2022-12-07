# define num 100
# include <stdio.h>

int change(){
    #undef num
    #define num 10
    return num;
}



int main()
{
    int a = 0 ;
    printf("%d\n", num);
    a = change();
    printf("%d\n", num+a);
}