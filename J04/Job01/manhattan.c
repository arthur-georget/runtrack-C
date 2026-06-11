#include "manhattan.h"
#include "stdio.h"

int manhattan(Point a, Point b){
    return ABS(b.x - a.x) + ABS(b.y - a.y);
}

int main(){
    Point a;
    a.x = 3;
    a.y = 2;
    Point b;
    b.x = 4;
    b.y = 9;
    printf("%i\n",manhattan(a,b));
    return 0;
}