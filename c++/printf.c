#include <stdio.h>
#include <limits.h>

int main()
{
    /*
    %c	输出一个单一的字符
    %hd、%d、%ld	以十进制、有符号的形式输出 short、int、long 类型的整数
    %hu、%u、%lu	以十进制、无符号的形式输出 short、int、long 类型的整数
    */
    printf("%c\n", 'a');// %c, print char
    
    int x1 = 123;
    printf("%d\n", x1);// %d, print interger
    
    unsigned int x2 = 123;
    printf("%u\n", x2);// %u, unsign interger

    int x9 = -1;
    printf("%u\n", x9);// %u, unsign interger // 4294967295 = 2^32 - 1

    float x3 = 123.00;
    printf("%f\n", x3);// %f, float

    double x4 = 123.00;
    printf("%lf\n", x4);// %lf, double

    printf("%s\n", "Hello World"); // %s for string 

    unsigned long x5 = 0x00000010;
    printf("%#X\n", x5); // 0X10
    printf("%#x\n", x5); // 0x10
    printf("%x\n", x5); // 10, show ()_16
    printf("%d\n", x5); // 16, show in ()_10
    
    char char_x = 0; // -128～+127
    unsigned char u_char_x = 0; // 0 ~ 255
    printf("sizeof(char_x) = %lu\n", sizeof(char_x)); // 1 byte
    printf("sizeof(u_char_x) = %lu\n", sizeof(u_char_x)); // 1 byte

    short int short_int_x = 0;
    unsigned short int u_short_int_x = 0;
    printf("sizeof(short_int_x) = %lu\n", sizeof(short_int_x)); // 2 byte
    printf("sizeof(u_short_int_x) = %lu\n", sizeof(u_short_int_x)); // 2 byte

    int int_x = 0; // -2^31 ~ 2^31 - 1
    unsigned int u_int_x = 0; // 0 ~ 2^32-1
    printf("sizeof(int_x) = %lu\n", sizeof(int_x)); // 4 byte
    printf("sizeof(u_int_x) = %lu\n", sizeof(u_int_x)); // 4 byte
    printf("INT_MIN = %d\n", INT_MIN);
    printf("INT_MAX = %d\n", INT_MAX);

    long int long_int_x = 0; // -2^63 ~ 2^63 - 1
    unsigned long int u_long_int_x = 0; // 0 ~ 2^64 - 1
    printf("sizeof(long_int_x)   = %lu\n", sizeof(long_int_x)); // 8 byte
    printf("sizeof(u_long_int_x) = %lu\n", sizeof(u_long_int_x)); // 8 byte

    long long long_long_int_x = 0; // -2^63 ~ 2^63 - 1
    printf("sizeof(long_long_int_x) = %lu\n", sizeof(long_long_int_x)); // 8 byte

    float float_x = 0.00;
    double double_x = 0.00;
    long double long_double_x = 0.00;
    printf("sizeof(float_x) = %lu\n", sizeof(float_x)); // 4 byte
    printf("sizeof(double_x) = %lu\n", sizeof(double_x)); // 8 byte
    printf("sizeof(long_double_x) = %lu\n", sizeof(long_double_x)); // 16 byte

    return 0;
}