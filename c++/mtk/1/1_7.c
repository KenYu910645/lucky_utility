# define num 100
# include <stdio.h>

int change(){
    #undef num // cancal the definition above 
    #define num 10 // define a new one
    return num;
}

int main(){
    int a = 0;
    printf("num = %d\n", num); // num = 10
    a = change();
    printf("Sum = %d\n", num + a); // Sum = 20
    return 0;
}