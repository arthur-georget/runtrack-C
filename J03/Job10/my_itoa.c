#include <stdio.h>
#include <stdlib.h>

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

int main(){
    int myInt = 1234567;
    char* charedInt = my_itoa(myInt);
    printf("%s \n", charedInt);
    free(charedInt);
    return 0;
}