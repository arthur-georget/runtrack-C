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
    if (album == NULL) return;
    printf("\"%s\" by \"%s\" released in %i.\n",album->title, album->artist, album->year);
}

int count_album_item(AlbumItem* list){
    int count = 0;
    AlbumItem* currentAlbum = list;
    while(currentAlbum != NULL){
        print_album(currentAlbum);
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

void reverse_list(AlbumItem **list){
    AlbumItem* prev = NULL;
    AlbumItem* current = *list;
    AlbumItem* next;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *list = prev;
}

void clear_list(AlbumItem **list){
    if (list == NULL || *list == NULL) return;
    AlbumItem* current = *list;
    while(current != NULL){
        AlbumItem* nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

void push_back_album(AlbumItem **list, AlbumItem *album){
    if (list == NULL || album == NULL) return;
    if (*list == NULL) {
        *list = album;
        return;
    }
    AlbumItem* current = *list;
    while(true){
        AlbumItem* nextNode = current->next;
        if (current->next == NULL){
            current->next = album;
            break;
        }
        current = nextNode;
    }
}

int main(){
    AlbumItem* mof = create_album_item("Metallica","Master of Puppets", 1986);
    AlbumItem** list = &mof;
    AlbumItem* ajfa = create_album_item("Metallica","...And Justice for All", 1988);
    AlbumItem* meta = create_album_item("Metallica","Metallica", 1991);
    push_back_album(list, ajfa);
    push_back_album(list, meta);

    count_album_item(mof);
    reverse_list(list);
    count_album_item(mof);
    
    clear_list(list);

    return 0;
}