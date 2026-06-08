#include <stdio.h>

int char_is_digit(char c){
    if (c < '0' || c > '9'){
        return 0;
    }
    return 1;
}

int str_is_digit(char *str){
    int i = 0;
    while((str[i]) != '\0'){
        printf("%i %i",i,char_is_digit(str[i]));
        if (char_is_digit(str[i]) != 1){
            ++i;
            return 0;
        }
        ++i;
    }
    return 1;
}

int main(){
    printf("oisjefoijsfe -> %i \n",str_is_digit("oisjefoijsfe"));
    printf("1243567432 -> %i \n",str_is_digit("1243567432"));
    printf("12435a6743 -> %i \n",str_is_digit("12435a6743"));
    return 0;
}