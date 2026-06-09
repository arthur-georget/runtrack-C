#include <stdio.h>
#include <stdlib.h>

int* array_clone(int* arr, int n){
    int* p = (int*) malloc(n*sizeof(int));
    for (int i = 0; i < n; ++i){
        *(p+i) = *(arr+i);
    }
    return p;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8};
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i){
        printf("%i", arr[i]);
    }
    printf("\n");
    int sizeToClone = 3;
    int* arrayClone = array_clone(arr, sizeToClone);

    if (arrayClone != NULL){
        for (int i = 0; i < sizeToClone; ++i){
            printf("%i", arrayClone[i]);
        }
        free(arrayClone);
    }
 
    return 0;
}