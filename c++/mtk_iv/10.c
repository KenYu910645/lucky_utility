# include <stdio.h>
int f(){
    static int i = 5;
    if(--i){
        f();
        printf("%d", i);
    }
    return 0;
}

int main (){
    f(); 
}