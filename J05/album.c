#include "album.h"

char *clean_alloc_copy(char *src, int len) {
    int start = 0;
    int end = len;
    
    while (start < end && (src[start] == ' ' || src[start] == '"')) {
        start++;
    }
    while (end > start && (src[end - 1] == ' ' || src[end - 1] == '"')) {
        end--;
    }
    
    char *dest = malloc(sizeof(char) * (end - start + 1));
    if (!dest) return 0;
    
    int i = 0;
    while (start < end) {
        dest[i++] = src[start++];
    }
    dest[i] = '\0';
    return dest;
}

int parse_int(char *src, int len) {
    int num = 0;
    int i = 0;
    while (i < len && src[i] == ' ') {
        i++;
    }
    while (i < len && src[i] >= '0' && src[i] <= '9') {
        num = num * 10 + (src[i] - '0');
        i++;
    }
    return num;
}

AlbumItem** parse_file(char* filePath){
    printf("%s\n", filePath);

    int openedFile = open(filePath, O_RDONLY);
    if (openedFile < 0) {
        printf("File not found.");
        return 0;
    }

    AlbumItem *head = 0;
    AlbumItem *tail = 0;
    
    char buffer[1024];
    int buffer_index = 0;
    char c;
    
    while (read(openedFile, &c, 1) > 0) {
        if (c != '\n' && buffer_index < 1023) {
            buffer[buffer_index++] = c;
        } else {
            if (buffer_index == 0) continue;
            
            int comma1 = -1;
            int comma2 = -1;
            
            for (int i = 0; i < buffer_index; i++) {
                if (buffer[i] == ',') {
                    if (comma1 == -1) {
                        comma1 = i;
                    } else if (comma2 == -1) {
                        comma2 = i;
                        break;
                    }
                }
            }
            
            if (comma1 != -1 && comma2 != -1) {
                AlbumItem *new_node = malloc(sizeof(AlbumItem));
                if (!new_node) break;
                
                new_node->artist = clean_alloc_copy(buffer, comma1);
                new_node->title = clean_alloc_copy(buffer + comma1 + 1, comma2 - comma1 - 1);
                new_node->year = parse_int(buffer + comma2 + 1, buffer_index - comma2 - 1);
                new_node->next = 0;
                
                if (head == 0) {
                    head = new_node;
                    tail = new_node;
                } else {
                    tail->next = new_node;
                    tail = new_node;
                }
            }
            buffer_index = 0;
        }
    }
    
    close(openedFile);
    
    AlbumItem **result = malloc(sizeof(AlbumItem*));
    if (!result) return 0;
    *result = head;
    
    return result;
}

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

int count_album_item(AlbumItem** list){
    int count = 0;
    AlbumItem* currentAlbum = *list;
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

void push_back_album(AlbumItem** list, AlbumItem* album){
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

void push_front_album(AlbumItem** list, AlbumItem* album){
    if (list == NULL || album == NULL) return;
    album->next = *list;
    *list = album;
}

void album_del_one(AlbumItem** list, AlbumItem *elem){
    AlbumItem* current = *list;
    AlbumItem* prev = NULL;
    while(current != elem && current != NULL){
        prev = current;
        current = current->next;
    }
    if(current == NULL){
        return;
    }
    prev->next = current->next;
    free(current);
}

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

int bandName(AlbumItem* a, AlbumItem* b){
    return my_strcmp(a->artist, b->artist);
}

int albumName(AlbumItem* a, AlbumItem* b){
    return my_strcmp(a->title, b->title);
}

int year(AlbumItem* a, AlbumItem* b){
    if (a->year < b->year){
        return -1;
    } else if (a->year > b->year){
        return 1;
    } else {
        return 0;
    }
}

void sort_album_by(AlbumItem** list, int (*cmp)(AlbumItem*, AlbumItem*)){
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
            if (next != NULL && cmp(current, next) > 0) {
                current->next = next->next;
                next->next = current;
                *prev = next;
                swapped = 1;
                current = next;
            }
        }
    }
}