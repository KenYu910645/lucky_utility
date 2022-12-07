# define N 5
# define Y(n) ((N+1)*n)
# include <stdio.h>


int main ()
{
    printf("%d \n", 2*(N+Y(3+2)));
}