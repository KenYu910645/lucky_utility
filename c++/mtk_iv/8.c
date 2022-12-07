# include <stdio.h>

void f (char** p){
    char *t;
    t = (p+= sizeof(int))[-1];
    printf("%s\n", t);

}



int main ()
{
    char* x[] = {"ab", "cd", "ef", "gh", "ij", "kl"};
    f(x);
    return 0;
}