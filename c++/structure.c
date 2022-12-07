#include <stdio.h>

// Union, all the member variable share the same memory space
// 他的大小由內部最大的那個資料型態來定義
union myUnion {
    float val_float;
    int   val_int;
    char  val_char;
};

// Structure
struct myStruct {
    char name[16]; 
    int age;
};

int main () {
    // Structure
    struct myStruct person1 = {"Amy", 20 }; // 初始化
    person1.age = 21; // 操作
    printf("person1.name = %s\n", person1.name);
    printf("person1.age = %d\n", person1.age);
    
    //Union, they share the same space
    union myUnion my_union;
    my_union.val_int   = 3;
    my_union.val_float = 3.14;
    printf("my_union.val_int = %d\n", my_union.val_int); // 1078523331
    printf("my_union.val_float = %f\n", my_union.val_float); // 3.14

    return 0;
}
