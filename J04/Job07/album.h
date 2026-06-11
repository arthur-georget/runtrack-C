typedef struct album_item{
    char *artist;
    char *title;
    int year;
    struct album_item *next;
} AlbumItem;