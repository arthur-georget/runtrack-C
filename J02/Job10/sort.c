#include <stdio.h>
#include <stdlib.h>

int* sort(int* array){
    int N = 0;
    while(array[N] != '\0'){
        ++N;
    }
    for(int i = 1; i < N; ++i){
        for (int j = 0; j < (N-i); ++j){
            printf("i: %i\nj: %i\n-------\n", i,j);
            if(array[j] > array[j+1]){
                int cache = array[j+1];
                array[j+1] = array[j];
                array[j] = cache;
            }
        }
    }
}

int main(){
    int array[] = {5,3,7,2,9,4,1,6,8};
    sort(array);
    int i = 0;
    while(array[i] != '\0'){
        printf("%i ", array[i]);
        ++i;
    }
    return 0;
}