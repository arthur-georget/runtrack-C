#include "stdio.h"
#include "stdlib.h"
#include "album.h"

Album* create_album(char* artist, char* title, int year){
    Album* newAlbum = malloc(sizeof(Album));
    newAlbum->artist = artist;
    newAlbum->title = title;
    newAlbum->year = year;
    return newAlbum;
};

void print_album(Album* album){
    printf("\"%s\" by \"%s\" released in %i.\n",album->title, album->artist, album->year);
};

int main(){
    Album* mof = create_album("Metallica","Master of Puppets", 1986);
    print_album(mof);
    free(mof);
    return 0;
}