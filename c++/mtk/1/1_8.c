// What's the program output?
# include <stdio.h>

void f (char** p){
    char *t;
    
    // p += sizeof(int);
    // printf("%s\n", *p);

    t = (p += sizeof(int))[-1];
    printf("%s\n", t);
}

int main (){
    char* x[] = {"ab", "cd", "ef", "gh", "ij", "kl"};
    f(x); // 'gh'
    return 0;
}