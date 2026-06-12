#include "album.h"

int main(){
    AlbumItem* mof = create_album_item("Metallica","Master of Puppets", 1986);
    AlbumItem** list = &mof;
    AlbumItem* ajfa = create_album_item("Metallica","...And Justice for All", 1988);
    AlbumItem* meta = create_album_item("Metallica","Metallica", 1991);
    AlbumItem* rtl = create_album_item("Metallica","Ride The Lightning", 1984);
    push_back_album(list, ajfa);
    push_back_album(list, meta);
    push_front_album(list,rtl);
    count_album_item(list);
    sort_album(list);
    count_album_item(list);
    
    clear_list(list);

    return 0;
}
