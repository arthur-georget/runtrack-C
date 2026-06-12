#include "album.h"

int main(){
    AlbumItem* mof = create_album_item("Metallica","Master of Puppets", 1986);
    AlbumItem** list = &mof;
    AlbumItem* ajfa = create_album_item("Metallica","...And Justice for All", 1988);
    AlbumItem* meta = create_album_item("Metallica","Metallica", 1991);
    AlbumItem* rtl = create_album_item("Metallica","Ride The Lightning", 1984);
    AlbumItem* tnt = create_album_item("ACDC","T.N.T", 1975);
    AlbumItem* bls = create_album_item("Black Sabbath","Black Sabbath", 1975);
    AlbumItem* rip = create_album_item("Megadeth","Rust In Peace", 1990);
    AlbumItem* ove = create_album_item("Motörhead","Overkill", 1979);
    push_back_album(list, ajfa);
    push_back_album(list, meta);
    push_back_album(list, tnt);
    push_back_album(list, bls);
    push_back_album(list, rip);
    push_back_album(list, ove);
    push_front_album(list,rtl);
    count_album_item(list);
    printf("-------Ordered by Band Name-------\n");
    sort_album_by(list,bandName);
    count_album_item(list);
    printf("-----Ordered by Album Name--------\n");
    sort_album_by(list,albumName);
    count_album_item(list);
    printf("---------Ordered by year----------\n");
    sort_album_by(list,year);
    count_album_item(list);
    clear_list(list);
    return 0;
}
