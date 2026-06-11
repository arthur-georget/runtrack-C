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

void str_to_lower(char* s){
    int i = 0;
    while (s[i] != '\0'){
        s[i] = to_lower(s[i]);
        ++i;
    }
}

void str_to_upper(char* s){
    int i = 0;
    while (s[i] != '\0'){
        s[i] = to_upper(s[i]);
        ++i;
    }
}

void str_switch_case(char* s){
    int i = 0;
    while (s[i] != '\0'){
        s[i] = switch_case(s[i]);
        ++i;
    }
}

int main(){
    char smallstr[] = "Je veux grandir!!";
    char bigstr[] = "JE VEUX RAPETISSER.";
    char weirdstr[] = "jE vEuX cHaNgEr...";
    printf("%s\n", smallstr);
    str_to_upper(smallstr);
    printf("%s\n", smallstr);
    printf("%s\n", bigstr);
    str_to_lower(bigstr);
    printf("%s\n", bigstr);
    printf("%s\n", weirdstr);
    str_switch_case(weirdstr);
    printf("%s\n", weirdstr);
    return 0;
}