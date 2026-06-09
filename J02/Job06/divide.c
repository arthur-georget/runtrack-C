#include <stdio.h>

void divide(int* val){
    (*val)/=2;
}

int main(){
    int a = 40;
    printf("%i \n", a);
    divide(&a);
    printf("%i \n", a);
    return 0;
}