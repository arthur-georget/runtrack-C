#include <stdio.h>

void print_address(int* n){
    printf("%p \n", (void*)n);
}

int main(){
    int n = 42;
    print_address(&n);
    return 0;
}