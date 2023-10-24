#include "linkedlist.h"
#include <stdio.h>

int main(){
    struct node* s1 = new("zc", "bad", '\0');
    struct node* s2 = new("abc", "bdd", '\0');

    printf("%d\n", compareNodes(s1, s2));
}