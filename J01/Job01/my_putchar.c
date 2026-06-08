#include <unistd.h>

int my_putchar(char c){
    write(1,&c,1);
    write(1,"\n",2);
    return 0;
}

int main(){
    my_putchar('e');
    return 0;
}