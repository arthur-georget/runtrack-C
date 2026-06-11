#include <stdio.h>

int factorial(int a){
    int result = 1;
    ++a;
    for (int i = 1; i < a; ++i){
        result *= i;
    }
    return result;
}

int main(){
    printf("0! = %i \n", factorial(0));
    printf("1! = %i \n", factorial(1));
    printf("2! = %i \n", factorial(2));
    printf("3! = %i \n", factorial(3));
    printf("4! = %i \n", factorial(4));
    printf("10! = %i \n", factorial(10));
    return 0;
}