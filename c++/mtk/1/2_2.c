// What's the output of this program
# include <stdio.h>
# define THRD 0x8

int main(){
    int ch = 26;
    if ( ch & 0xF > THRD){
        printf("MORE %d\n", ch & 0xF);
    }
    else{
        printf("LESS %d\n", ch & 0xF);
    }
    return 0;
}