#include <stdio.h>

int sum_array(int* arr, int n){
    int sum = 0;
    for (int i = 0; i < n; ++i){
        sum += *(arr+i);
    }
    return sum;
}

int main(){
    int arr[] = {4,2,5,20};
    printf("%i", sum_array(arr,(sizeof(arr) / sizeof(arr[0]))));
    return 0;
}