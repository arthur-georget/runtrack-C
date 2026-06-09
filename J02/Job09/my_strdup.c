#include <stdio.h>
#include <stdlib.h>

char* my_strdup(char* src){
    int i = 0;
    while(src[i] != '\0'){
        ++i;
    }
    char* dst = (char*)malloc(i*sizeof(char));
    for (int j = 0; j < i; ++j){
        dst[j] = src[j];
    }
    dst[i] = '\0';
    return dst;
}

int main(){
    char originString[] = "Hello World!";
    char* dupString = my_strdup(originString);
    printf("originString: %p %s \n", &originString, originString);
    printf("dupString: %p %s \n", &dupString, dupString);
    free(dupString);
    return 0;
}