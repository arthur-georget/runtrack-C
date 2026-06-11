#include <stdio.h>

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

int main(){
    char* myStrToConvert = "-234567564";
    int convertedStr = my_atoi(myStrToConvert);
    printf("%i \n",convertedStr);
    return 0;
}