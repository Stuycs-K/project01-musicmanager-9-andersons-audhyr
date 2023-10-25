
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include <string.h>

int print(struct node *s, int n){
    printf("[%d]Song: %s || Artist: %s\n", n, s->song, s->artist);
}

struct node* new(char n[], char Artist[], struct node *next){
    
    struct node *a=  malloc(208);
    strcpy(a->song, n);
    strcpy(a->artist, Artist);
    a->next = next;
    return a;

}

struct node * insert_front(struct node * next, char* n, char* a){
    return new(n, a, next);

}

void print_list(struct node * front){
    for(int i = 0; !front == '\0'; i++){
        print(front, i);
        front = front->next;
    }

}

struct node * free_list(struct node * front){
    struct node * next;
    while(!front=='\0'){
        next =  front->next;
        free(front);
        front = next;

    }
    return front;

}

int compareNodes(struct node* c1, struct node*c2){
    int compareArtist = strcmp(c1->artist, c2->artist);
    if(compareArtist < 0) return -1;
    if(compareArtist > 0) return 1;

    int compareSong = strcmp(c1->song, c2->song);
    if(compareSong < 0) return -1;
    if(compareSong > 0) return 1;

    return 0;
} 
struct node * songpoint(struct node * front, char* song, char* artist){
    if(strcmp(front->song, song)==0 && strcmp(front->artist, artist)==0){
        return front;
    }
    return songpoint(front->next, song, artist);
}

struct node* insertOrder(struct node* insertTo, struct node*insert){
    struct node *front = insertTo;
    if(insertTo == NULL || compareNodes(insert, insertTo) == -1){
        insert->next = insertTo;
        return insert;
    }

    while(insertTo != NULL){
        if(insertTo->next == NULL){
            insertTo->next = insert;
            return front; 
        }

        if(compareNodes(insert, insertTo) == 1 && compareNodes(insert, insertTo->next) == -1){
            insert->next = insertTo->next;
            insertTo->next = insert;
            return front;
        }

        insertTo = insertTo->next;
    }

    return front;
}
struct node * artistpoint(struct node * front, char* artist){
    if(strcmp(front->artist, artist)==0){
        return front;
    }
    return artistpoint(front->next, artist);
}

struct node *randomSong(struct node *list){
    struct node *front = list;
    int size = 0;
    
    while(list != NULL){
        size++;
        list = list->next;
    }
    
    for(int i = 0; i < rand()%size; i++) front = front->next; 

    return front;
}

struct node *removeSong(struct node *list, char* song, char* artist){
    struct node *front = list;
    struct node *remove;

    if(strcmp(list->song, song) == 0 && strcmp(list->artist, artist) == 0){
        front = list->next;
        free(list);
        return front;
    }

    while(list->next != NULL){
        remove = list->next;
        if(strcmp(remove->song, song) == 0 && strcmp(remove->artist, artist) == 0){
            list->next = remove->next;
            free(remove);
            return front;
        }
        list = list->next;
    }

    return front;
}
