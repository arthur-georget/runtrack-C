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
}

void print_album(AlbumItem* album){
    printf("\"%s\" by \"%s\" released in %i.\n",album->title, album->artist, album->year);
}

int count_album_item(AlbumItem* list){
    int count = 0;
    AlbumItem* currentAlbum = list;
    while(currentAlbum != NULL){
        currentAlbum = currentAlbum->next;
        ++count;
    }
    return count;
}

int main(){
    AlbumItem* mof = create_album_item("Metallica","Master of Puppets", 1986);
    AlbumItem* ajfa = create_album_item("Metallica","...And Justice for All", 1988);
    AlbumItem* meta = create_album_item("Metallica","Metallica", 1991);
    mof->next = ajfa;
    ajfa->next = meta;
    print_album(mof);
    printf("Number of albums: %i",count_album_item(mof));
    free(mof);
    free(ajfa);
    free(meta);
    return 0;
}