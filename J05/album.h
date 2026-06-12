#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct album_item{
    char *artist;
    char *title;
    int year;
    struct album_item *next;
} AlbumItem;

signed my_strcmp(char *s1, char *s2);

AlbumItem* create_album_item(char* artist, char* title, int year);

void print_album(AlbumItem* album);

int count_album_item(AlbumItem** list);

AlbumItem* find_album(AlbumItem* list, const char* title);

void reverse_list(AlbumItem **list);

void clear_list(AlbumItem **list);

void push_back_album(AlbumItem** list, AlbumItem* album);

void push_front_album(AlbumItem** list, AlbumItem* album);

void album_del_one(AlbumItem** list, AlbumItem *elem);

signed my_strcmp(char *s1, char *s2);

void sort_album_by(AlbumItem **list, int (*cmp)(AlbumItem*, AlbumItem*));

int bandName(AlbumItem* a, AlbumItem* b);

int albumName(AlbumItem* a, AlbumItem* b);

int year(AlbumItem* a, AlbumItem* b);