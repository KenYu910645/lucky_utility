// What's the output of this program?
# include <stdio.h>
int func(){
    static int i = 5;
    if(--i){
        func();
        printf("%d ", i);
    }
    return 0;
}

int main (){
    func(); // 0 0 0 0
    return 0;
}