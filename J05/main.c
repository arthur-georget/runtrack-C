#include "album.h"

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("No arguments provided: please provide a file path and 'artist','title' or year.\n");
        return 1;
    }
    AlbumItem** list = parse_file(argv[1]);
    count_album_item(list);
    return 0;
}