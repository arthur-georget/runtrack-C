#include <stdio.h>

int my_strlen(char* c){
    int i = 0;
    while ((c[i]) != '\0'){
        ++i;
    }
    return i;
}

int main(){
    int len = my_strlen("Wololo welele");
    printf("%i",len);
    return 0;
}