#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include <string.h>

int print(struct node s, int n){
    printf("[%d] Song %s Artist %s\n", n, s.name, s.artist);
}

struct node* new(char n[], char Artist[], struct node *next){
    
    struct node *a=  malloc(208);
    strcpy(a->name, n);
    strcpy(a->artist, Artist);
    a->next = next;
    return a;

}

struct node * insert_front(struct node * next, char* n, char* a){
    new(n, a, next);

}

void print_list(struct node * front){
    for(int i = 0; !front == '\0'; i++){
        print(*front, i);
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
