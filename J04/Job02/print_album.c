#include "album.h"
#include "stdio.h"

void print_album(Album* album){
    printf("\"%s\" by \"%s\" released in %i.\n",album->title, album->artist, album->year);
};

int main(){
    Album mof;
    mof.artist = "Metallica";
    mof.title = "Master of Puppets";
    mof.year = 1986;
    print_album(&mof);
    return 0;
}