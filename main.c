#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
int main(){
    struct node * front = insert_front( '\0',"Bohemian Rhapsody", "Queen");
    front = insert_front( front,"Build Me Up Buttercup", "The Foundations");
    print_list(front);
    struct node * mysong=songpoint(front, "Bohemian Rhapsody", "Queen");
    printf("%s %s\n", mysong->song, mysong->artist);
    
}