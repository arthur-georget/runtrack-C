#include <stdio.h>
#include <stdlib.h>

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

int main(){
    int myInt = 127;
    char* hexedInt = itoa_hex(myInt);
    printf("%s \n", hexedInt);
    free(hexedInt);
    return 0;
}