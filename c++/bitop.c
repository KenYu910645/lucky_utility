
#include <stdio.h>
//XOR
// 0110 a 
// 1010 b
//------
// 1100 a^b
// ----
// 1010 a^(a^b)
inline void swap(char *a,char *b){
    *a= *a^*b;
    *b= *a^*b;
    *a= *a^*b;
}

// 101 <- 5
// 100 <- 4
// ----
// 100 <- 不是二的次方的話，會有東西
// 
// 100 <- 4
// 011 <- 3
// ----
// 000 <- 是二的次方一定沒東西
// use bitops to decide whether n is 2^N
inline int is_2_N(int n){
    return (!(n&n-1) && n!=0);
}

int main()
{
    // 4 byte
    unsigned int num_a = 0x00001111; // 0000 0000 0000 0000 0001 0001 0001 0001
    unsigned int num_b = 0x0000FFFF; // 0000 0000 0000 0000 1111 1111 1111 1111

    // AND operation 
    printf("%#x\n", num_a & num_b); // 0x1111
    // OR operation
    printf("%#x\n", num_a | num_b); // 0xffff
    // NOT operation
    printf("%#x\n", ~num_b); // 0xffff0000
    // XOR operation (addition without carry)
    printf("%#x\n", num_a ^ num_b); // 0xeeee, 0000 0000 0000 0000 1110 1110 1110 1110
    // << left shift
    printf("%#x\n", num_a << 4); // 0x11110
    printf("%#x\n", num_a << 1); // 0x2222
    // >> right shift
    printf("%#x\n", num_a >> 4); // 0x111
    printf("%#x\n", num_a >> 1); // 0x888

    char c1 = 'A';
    char c2 = 'D';
    printf("c1, c2 = %c, %c \n", c1, c2);
    swap(&c1, &c2);
    printf("c1, c2 = %c, %c \n", c1, c2);
    
    printf("%d\n", is_2_N(5));
    printf("%d\n", is_2_N(4));

    return 0;
}