#include <stdio.h>

int is_digit(char c){
    if (c >= '0' && c <= '9'){
        return 1;
    }
    return 0;
}

int is_lower(char c){
    if (c >= 'a' && c <= 'z'){
        return 1;
    }
    return 0;
}

int is_upper(char c){
    if (c >= 'A' && c <= 'Z'){
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

int main(){
    printf("a is digit? %i\n",is_digit('a'));
    printf("5 is digit? %i\n",is_digit('5'));
    printf("! is digit? %i\n",is_digit('!'));
    printf("a is lower? %i\n",is_lower('a'));
    printf("A is lower? %i\n",is_lower('A'));
    printf(": is lower? %i\n",is_lower(':'));
    printf("a is upper? %i\n",is_upper('a'));
    printf("W is upper? %i\n",is_upper('W'));
    printf("t is alpha? %i\n",is_alpha('t'));
    printf("5 is alpha? %i\n",is_alpha('5'));
    printf("Y is alpha? %i\n",is_alpha('Y'));
    printf("a is print? %i\n",is_print('a'));
    printf("* is print? %i\n",is_print('*'));
    return 0;
}