#include <stdio.h>

char *my_strcpy(char *dst, char *src){
    int i = 0;
    while(src[i] != '\0'){
        dst[i] = src[i];
        ++i;
    }
    dst[i] = '\0';
    return dst;
}

int main(){
    char originString[] = "Hello World!";
    char targetString[] = "Bonjour le monde!";
    printf("%s \n", originString);
    printf("%s \n", targetString);
    printf("%s \n", my_strcpy(targetString, originString));
    printf("%s \n", originString);
    printf("%s \n", targetString);
    return 0;
}