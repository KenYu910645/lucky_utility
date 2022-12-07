#include <stdio.h>

int main(void) {
    unsigned int  a = 0xFFFF0101; // 4 byte
    unsigned char b = (unsigned char)a; // 1 byte, 0 ~ 255, only get 0x01
    char *c = (char *) &a;
    printf("a=%#x\n", a); // ffff0101
    printf("b=%#x\n", b); // b=0x1
    printf("c=%#x\n", *c); // c=0x1
    return 0;
}