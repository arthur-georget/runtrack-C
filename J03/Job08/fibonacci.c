#include <stdio.h>

int fibonacci_it(int n){
    int preprev = 0;
    int prev = 1;
    int curr = 0;
    for (int i = 0; i < n; ++i){
        curr = preprev + prev;
        preprev = prev;
        prev = curr; 
    }
    return curr;
}

// It's working but it's a bit messy I guess
int fibonacci_rec(int prevprev, int prev, int n){
    int result = prevprev + prev;
    //printf("%i -> %i \n",n,result);
    while (n >1){
        result = fibonacci_rec(prev, result, n-1);
        n=1;
    }
    return result;
}

int main(){
    printf("%i \n",fibonacci_it(7));
    printf("%i \n",fibonacci_rec(0,1,7));
}