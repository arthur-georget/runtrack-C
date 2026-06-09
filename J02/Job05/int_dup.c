#include <stdio.h>
#include <stdlib.h>

int* int_dup(int value){
    int* p = (int*) malloc(sizeof(int));
    *p = value;
    return p;
}

int main(){
    int a = 42;
    int* pa = &a;
    printf("a: %i \n", *pa);
    int* pdup = int_dup(a);
    printf("pa: %p \n", (void*)pa);
    printf("a: %i \n", *pa);
    printf("pdup: %p \n", (void*)pdup);
    printf("dup: %i \n", *pdup);
}