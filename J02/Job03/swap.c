#include <stdio.h>

void swap(int* a, int* b){
    int cache = *a;
    *a = *b;
    *b = cache;
}

int main(){
    int a = 34;
    int b = 62;
    printf("a: %i \n", a);
    printf("b: %i \n", b);
    swap(&a,&b);
    printf("a: %i \n", a);
    printf("b: %i \n", b);
    return 0;
}