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
void printlib(struct node ** lib){
    for(int i =0; i<27;i++){
        printf("%c\n", i+65);
        print_list(lib[i]);
    }

}
void printbylett(struct node ** lib, char* lett){
        printf("%s\n", lett);
        print_list(lib[*lett-65]);
    }

