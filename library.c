#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include <string.h>

struct node ** newlibrary(){
    struct node ** lib= calloc(27,sizeof(struct node *));
    return lib;


}
struct node ** addnode(char* song, char* artist, struct node ** lib){
    if(artist[0]-65<26 && artist[0] -65 >=0){
     lib[artist[0]-65] =insertOrder(lib[artist[0]-65], new(song, artist, NULL));
     return lib;}
    else{
        lib[26] =insertOrder(lib[26], new(song, artist, NULL));
     return lib;
    }

}

void printlib(struct node ** lib){
    for(int i =0; i<27;i++){
        printf("%c\n", i+65);
        print_list(lib[i]);
    }

}
void printbylett(struct node ** lib, char* lett){
        printf("%s\n", lett);
        if(*lett -65<26 && *lett -65>=0){
        print_list(lib[*lett-65]);}
        else{
            print_list(lib[26]);
        }
    }




struct node  * songInLibrary(struct node **lib, char *song, char *artist){
     if(artist[0]-65<26 && artist[0] -65 >=0){
    struct node *list = lib[artist[0]-65];
    return songpoint(list, song, artist);}
     else{
        struct node *list = lib[26];
     return songpoint(list, song, artist);
    }
}

struct node  * findArtist(struct node **lib, char *artist){
    struct node *list = lib[artist[0]-65];
    return artistpoint(list, artist);
}

void shufflePrint(struct node **lib, int n){
    struct node *list;

    int isEmpty = 1;
    for(int i = 0; i < 27; i++) if(lib[i] != NULL) isEmpty = 0;
    if(isEmpty) return;

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
void printartist(struct node **lib, char * artist){
    struct node *list = findArtist(lib, artist);
    int i = 0;
    while(strcmp(list->artist,artist)==0){
        print(list,i);
        if(list->next == NULL){break;}
        list = list->next;
        i++;
    }
}

struct node * deletesong(struct node ** lib, char* song, char* artist){
    if(artist[0]-65<26 && artist[0] -65 >=0){
        return removeSong(lib[artist[0]-65],song,artist);
    }
    else{
        return removeSong(lib[26],song,artist);
    }

}


