#include "album.h"

signed my_strcmp(char *s1, char *s2){
    int i = 0;
    while(s1[i] != '\0'){
        if(s2[i] == '\0' || s1[i] > s2[i]){
            return 1;
        } else if (s1[i] < s2[i]){
            return -1;
        }
        ++i;
    }
    if(s2[i] == '\0'){
        return 0;
    }
    return -1;
}

//https://stackoverflow.com/questions/32653316/bubble-sorting-a-linked-list-in-c
void sort_album(AlbumItem** list){
    if (list == NULL || *list == NULL || (*list)->next == NULL) {
        return;
    }
    int swapped = 1;
    while(swapped){
        AlbumItem** prev = list;
        AlbumItem* current;
        AlbumItem* next;

        swapped = 0;
        for(current = *list; current != NULL; prev = &current->next, current = current->next){
            next = current->next;
            if (next != NULL && my_strcmp(current->title, next->title) > 0) {
                current->next = next->next;
                next->next = current;
                *prev = next;
                swapped = 1;
                current = next;
            }
        }
    }
}