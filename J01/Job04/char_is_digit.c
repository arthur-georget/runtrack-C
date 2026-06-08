#include <stdio.h>

int char_is_digit(char c){
    if (c < '0' || c > '9'){
        return 0;
    }
    return 1;
}

int main(){
    printf("3 -> %i \n",char_is_digit('3'));
    printf("a -> %i \n",char_is_digit('a'));
    printf("! -> %i \n",char_is_digit('!'));
    printf("7 -> %i \n",char_is_digit('7'));
    return 0;
}