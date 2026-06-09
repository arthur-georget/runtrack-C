#include <stdio.h>
#include <stdlib.h>

void array_delete(int** arr){
    free(*arr);
    (*arr) = NULL;
}

int main(){
    int* arr = (int*)malloc(5* sizeof(int));
    array_delete(&arr);
    if (arr == NULL){
        printf("arr successfully deleted.");
    }
}