#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include <string.h>

struct node ** newlibrary(){
    struct node ** lib= calloc(27,sizeof(struct node *));
    return lib;


}
struct node ** addnode(char* song, char* artist, struct node ** lib){
     lib[artist[0]-65] =insertOrder(lib[artist[0]-65], new(song, artist, NULL));
     return lib;

}

struct node  * songInLibrary(struct node **lib, char *song, char *artist){
    struct node *list = lib[artist[0]-65];
    return songpoint(list, song, artist);
}

struct node  * findArtist(struct node **lib, char *artist){
    struct node *list = lib[artist[0]-65];
    return artistpoint(list, artist);
}

void shufflePrint(struct node **lib, int n){
    struct node *list;
    for(int i = 0; i < n; i++){
        list = NULL;
        while(list == NULL) list = lib[rand()%27];
        print(randomSong(list), i);
    }
}

struct node ** clearLibrary(struct node **lib){
    for(int i = 0; i < 27; i++){
        lib[i] = free_list(lib[i]);
    }

    return lib;
}