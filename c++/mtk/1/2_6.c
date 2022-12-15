// Whats the output
# include <stdio.h>

void func(){
    static int i = 0;
    i++;
    printf("%d", i);
}

int main(){
    func();func();func();func();
    func();func();func();func();
    // Output is 12345678
}
