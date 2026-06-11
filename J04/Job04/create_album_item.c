#include "stdio.h"
#include "stdlib.h"
#include "album.h"

AlbumItem* create_album_item(char* artist, char* title, int year){
    AlbumItem* newAlbum = malloc(sizeof(AlbumItem));
    newAlbum->artist = artist;
    newAlbum->title = title;
    newAlbum->year = year;
    newAlbum->next = NULL;
    return newAlbum;
};

void print_album(AlbumItem* album){
    printf("\"%s\" by \"%s\" released in %i.\n",album->title, album->artist, album->year);
};

int main(){
    AlbumItem* mof = create_album_item("Metallica","Master of Puppets", 1986);
    print_album(mof);
    free(mof);
    return 0;
}