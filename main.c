#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    struct node * front = insert_front( '\0',"Bohemian Rhapsody", "Queen");
    front = insert_front( front,"Build Me Up Buttercup", "The Foundations");
    print_list(front);
    struct node * mysong=songpoint(front, "Bohemian Rhapsody", "Queen");
    printf("%s %s\n", mysong->song, mysong->artist);
    char artists[10][35] = {"Apple Metal", "Apple Metal", "Apple Metal", "Megaapple", "Megaapple", "Megaapple", "Augustus's Poor Apple", "Japan Panic", "Japan Panic", "Japan Panic"};
    char songs[10][35] = {"Classic Misery", "Burning Revolution", "Hang Loose Dreams", "Without You, I Can't Feel Silence", "Honey, You Are My Dawing", "Deep Festival", "Afraid Of Blame", "Funny Train", "Fusion Light", "Complete Bird"};

    struct node* playlist = NULL;

    for(int i = 0; i < 10; i++) playlist = insertOrder(playlist, new(songs[i], artists[i], NULL));

    for(int i = 0; i < 10; i++){
        print(playlist, i);
        playlist = playlist->next;
    }

}