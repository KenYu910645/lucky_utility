#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main() {
  // 用來管理動態記憶體的指標
  int *dynArr1;
  int *dynArr2;

  // 指定空間大小
  int arrLen = 10;

  // 取得記憶體空間
  // void* means all kind of pointer can pass in 
  dynArr1 = (int *)malloc(arrLen* sizeof(int));// allocate how many byte for this array 
  dynArr2 = (int *)calloc(arrLen, sizeof(int));
  // if( dynArr1 == NULL ) {
  //   // 無法取得記憶體空間
  //   fprintf(stderr, "Error: unable to allocate required memory\n");
  //   return 1;
  // }

  // 使用動態取得的記憶體空間
  int i;
  for (i = 0; i < arrLen; ++i) {
    // dynArr1[i] = i;
    printf("%d ", dynArr1[i]);
  }
  printf("\n");

  for (i = 0; i < arrLen; ++i) {
    // dynArr1[i] = i;
    printf("%d ", dynArr2[i]);
  }
  printf("\n");

  // 釋放記憶體空間
  free(dynArr1);
  free(dynArr2);

  // memcpy
  char src[] = "***";
  char dest[] = "abcdefg";
  printf("Before memcpy() : %s\n", dest);
  memcpy(dest, src, strlen(src));
  printf("After memcpy() : %s\n", dest);

  return 0;
}