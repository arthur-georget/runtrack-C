#include <unistd.h>

int my_putchar(char c){
    write(1,&c,1);
    return 0;
}

int my_putstr(char *c){
    int i = 0;
    while((c[i]) != '\0'){
        my_putchar(c[i]);
        ++i;
    }
    write(1,"\n",2);
    return 0;
}

int main(){
    my_putchar('e');
    write(1,"\n",2);
    my_putstr("soeijfosiejfio");
    return 0;
}