#include <stdio.h>

int power(int n, int power){
    int result = 1;
    for (int i = 0; i < power ; ++i){
        result *= n;
    }
    return result;
}

int main(){
    int a = 5;
    int b = 3;
    printf("%i",power(a,b));
    return 0;
}