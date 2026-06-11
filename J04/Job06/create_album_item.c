#include "stdio.h"
#include "stdlib.h"
#include "album.h"
#include "stdbool.h"

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

AlbumItem* find_album(AlbumItem* list, const char* title){
    AlbumItem* currentAlbum = list;
    while(currentAlbum != NULL){
        int i = 0;
        bool titleMatch = true;
        while(currentAlbum->title[i] != '\0'){
            if (currentAlbum->title[i] != title[i]){
                titleMatch = false;
                break;
            }
            ++i;
        }
        if (title[i] != '\0'){
            titleMatch = false;
        }
        if (titleMatch == true){
            return currentAlbum;
        }
        currentAlbum = currentAlbum->next;
    }
    return NULL;
}

int main(){
    AlbumItem* mof = create_album_item("Metallica","Master of Puppets", 1986);
    AlbumItem* ajfa = create_album_item("Metallica","...And Justice for All", 1988);
    AlbumItem* meta = create_album_item("Metallica","Metallica", 1991);
    mof->next = ajfa;
    ajfa->next = meta;
    print_album(mof);
    printf("Number of albums: %i\n",count_album_item(mof));
    printf("\"%s\" found!\n",find_album(mof,"...And Justice for All")->title);
    free(mof);
    free(ajfa);
    free(meta);
    return 0;
}