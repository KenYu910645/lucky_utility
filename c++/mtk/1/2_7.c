// Completet the program in the blank space, so that the function can confirm that that
// whether p has data with low 8 bit as 0 and high 8 bits as non 0, return 1 that is the case

// I think this question is a bit weird. Because it give us 4 bytes data to work with, and 
// ask us to check low 8 bit and 8 high bit, while the data has 32 bits.
// Personally, I think checking low 16 bits and high 16 bits will be more reasonable.

# include <stdio.h>

int fun(unsigned int *p, int len){
    for (int i = 0; i < len; i++){
        if ( !(*p << 16) && (*p >> 16) ){ // Ask you if fill in the condition
            return 1;
        }
        p++;
    }
    return 0;
}

int main(){
    unsigned int test[] = {0x00560000, 0x34022500, 0x1000fee3};
    printf("%d\n", fun(&test[0], 3));  // Ask you if fill the function's arguments
    return 0;
}
