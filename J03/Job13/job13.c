#include <stdio.h>
#include <stdlib.h>

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

int sum(int* nArr, int size){
    int result = 0;
    for (int i = 0; i < size; ++i){
        result += nArr[i];
    }
    return result;
}

int mean(int* nArr, int size){
    if (size == 0) return 0;
    int mean = 0;
    for(int i = 0; i < size; ++i){
        mean += nArr[i];
    }
    mean /= size;
    return mean;
}

int main(int argc, char *argv[]){
    int arrSize = argc-1;
    int* nArr = malloc((arrSize)*sizeof(int));
    for (int i=1; i < argc; i++){
        nArr[i-1] = my_atoi(argv[i]);
    }
    printf("%i\n",sum(nArr, arrSize));
    printf("%i\n",mean(nArr, arrSize));
    free(nArr);
    return 0;
}