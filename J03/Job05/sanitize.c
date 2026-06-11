#include <stdio.h>

char sanitize(char c){
    if (c < 32){
        return '?';
    } else {
        return c;
    }
}

void str_sanitize(char* s){
    int i = 0;
    while(s[i] != '\0'){
        s[i] = sanitize(s[i]);
        ++i;
    }
}

int main(){
    char unprintableStr[] = "TOTO !\n\a\b\t\v\f\r";
    str_sanitize(unprintableStr);
    printf("%s", unprintableStr);
    return 0;
}