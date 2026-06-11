#include <stdio.h>

int is_digit(char c){
    if (c >= '0' && c <= '9'){
        return 1;
    }
    return 0;
}

int is_alpha(char c){
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
        return 1;
    }
    return 0;
}

int is_print(char c){
    if (c >= '!' && c <= '~'){
        return 1;
    }
    return 0;
}

int str_is_digit(char *s){
    int isDigit = 1;
    int i = 0;
    while (s[i] != '\0'){
        if ( is_digit(s[i]) == 0 ){
            isDigit = 0;
        }
        ++i;
    }
    return isDigit;
}

int str_is_alpha(char *s){
    int isAlpha = 1;
    int i = 0;
    while (s[i] != '\0'){
        if ( is_alpha(s[i]) == 0 ){
            isAlpha = 0;
        }
        ++i;
    }
    return isAlpha;
}

int str_is_print(char *s){
    int isPrint = 1;
    int i = 0;
    while (s[i] != '\0'){
        if ( is_print(s[i]) == 0 ){
            isPrint = 0;
        }
        ++i;
    }
    return isPrint;
}

int main(){
    printf("23455E234 is digit? %i\n",str_is_digit("23455E234"));
    printf("5876453 is digit? %i\n",str_is_digit("5876453"));
    printf("_è-(')4 is digit? %i\n",str_is_digit("'_è-(')4"));
    printf("tazerztey is alpha? %i\n",str_is_alpha("tazerztey"));
    printf("taze5rztey is alpha? %i\n",str_is_alpha("taze5rztey"));
    printf("_è-(')4 is alpha? %i\n",str_is_alpha("_è-(')4"));
    printf("_è-(')4 is print? %i\n",str_is_print("_è-(')4"));
    printf("AZEREEG54323ee4(-()) is print? %i\n",str_is_print("AZEREEG54323ee4(-())"));
    return 0;
}