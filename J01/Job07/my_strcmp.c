#include <stdio.h>

signed my_strcmp(char *s1, char *s2){
    int i = 0;
    while(s1[i] != '\0'){
        if(s2[i] == '\0' || s1[i] > s2[i]){
            return 1;
        } else if (s1[i] < s2[i]){
            return -1;
        }
        ++i;
    }
    if(s2[i] == '\0'){
        return 0;
    }
    return -1;
}

int main(){
    printf("ABC %i ABD \n", my_strcmp("ABC","ABD"));
    printf("ABD %i ABC \n", my_strcmp("ABD","ABC"));
    printf("AB %i ABD \n", my_strcmp("AB","ABD"));
    printf("ABD %i AB \n", my_strcmp("ABD","AB"));
    printf("ABC %i ABC \n", my_strcmp("ABC","ABC"));
}