#include <stdio.h>

int main(){
    int input[5] = {5, 8, 4, 9, 1};
    int query[5] = {2, 1, 3, 4, 0};

    // sort input, bubble sort
    int j;
    for (j = 0; j < 5; j++){
        int i;
        for (i = 1; i < 5; i++){
            if (input[i-1] > input[i] ){ // swap
                int tmp = input[i-1];
                input[i-1] = input[i];
                input[i] = tmp;
            }
        }
    }

    for (j = 0; j < 5; j++){
        printf("%d\n", input[query[j]]); // 5, 4, 8 , 9 , 1
    }


    return 0;
}

