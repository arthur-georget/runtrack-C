#include <stdio.h>

char to_lower(char c){
    if (c >= 'A' && c <= 'Z'){
        return c + 32;
    } else {
        return c;
    }
}

char to_upper(char c){
    if (c >= 'a' && c <= 'z'){
        return c - 32;
    } else {
        return c;
    }
}

char switch_case(char c){
    if (c >= 'A' && c <= 'Z'){
        return to_lower(c);
    } else if (c >= 'a' && c <= 'z'){
        return to_upper(c);
    }
    else{
        return c;
    }
}

int main(){
    printf("a to %c\n", switch_case('a'));
    printf("A to %c\n", switch_case('A'));
    printf(": to %c\n", switch_case(':'));
    return 0;
}