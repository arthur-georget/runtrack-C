#include <stdio.h>

void increment(int* n){
    (*n)++;
}

int main(){
    int n = 0;
    printf("%i \n", n);
    increment(&n);
    printf("%i \n", n);
    return 0;
}