#include <stdio.h>
#include <stdlib.h>

int factorial(int a){
    int result = 1;
    ++a;
    for (int i = 1; i < a; ++i){
        result *= i;
    }
    return result;
}

int fibonacci_it(int n){
    int preprev = 0;
    int prev = 1;
    int curr = 0;
    for (int i = 0; i < n; ++i){
        curr = preprev + prev;
        preprev = prev;
        prev = curr; 
    }
    return curr;
}

int my_atoi(char* str){
    int i = 0;
    int sign = 1;
    int result = 0;

    if(str == NULL){
        return 0;
    }

    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)){
        i++;
    }

    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
        {
            sign = -1;
        }
        i++;
    }

    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return (result * sign);
}

char* my_itoa(int n){
    int countDecimals = 1;
    int nCopy = n;
    while (nCopy >= 10){
        nCopy /= 10;
        ++countDecimals;
    }
    char* charedInt = malloc((countDecimals+1)*sizeof(char));
    
    if (charedInt == NULL) return NULL;
    
    charedInt[countDecimals] = '\0';

    for (int i = countDecimals -1; i >= 0; --i){
        charedInt[i] = (char)(n%10) + '0';
        n /= 10;
    }
    return charedInt;
    //printf("Decimals: %i", countDecimals);
}

char* itoa_hex(int n){
    int countHex = 1;
    int nCopy = n;
    while (nCopy >= 16){
        nCopy /= 16;
        ++countHex;
    }
    char* charedInt = malloc((countHex+1)*sizeof(char));
    
    if (charedInt == NULL) return NULL;
    
    charedInt[countHex] = '\0';

    for (int i = countHex -1; i >= 0; --i){
        char hexChar;
        switch (n%16)
        {
        case 10:
            hexChar = 'A';
            break;
        case 11:
            hexChar = 'B';
            break;
        case 12:
            hexChar = 'C';
            break;
        case 13:
            hexChar = 'D';
            break;
        case 14:
            hexChar = 'E';
            break;
        case 15:
            hexChar = 'F';
            break;
        default:
            hexChar = n%16 + '0';
            break;
        }
        charedInt[i] = hexChar;
        n /= 16;
    }
    return charedInt;
}

int main(int argc, char *argv[]){
    int n = my_atoi(argv[1]);
    char* dec =  my_itoa(n);
    char* hex = itoa_hex(n);
    printf("Vous avez entré %i.\n", n);
    printf("Voici sa valeur en décimal: %s\n",dec);
    printf("Voici sa valeur en hexadécimal: %s\n", hex);
    if (n < 20){
        if (n < 10){
            printf("Voici sa factorielle: %i\n", factorial(n));
        }
        printf("Voici sa %i-eme Fibonacci: %i\n", n, fibonacci_it(n));
    }
    free(dec);
    free(hex);
    return 0;
}