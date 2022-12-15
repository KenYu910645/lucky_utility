// What't the program output?
# include <stdio.h>
# define N 5
# define Y(n) ((N+1)*n)

int main (){
    printf("%d \n", 2*(N+Y(3+2))); // 50
}