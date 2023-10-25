#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    char artists[10][35] = {"Apple Metal", "Sharp Sharp", "King Black", "Between the Ants and Me", "Megaapple", "Augustus's Poor Apple", "No Apple", "The Poor Ants", "Japan Panic", "The Sharp Heroes of Japan"};
    char songs[10][35] = {"Classic Misery", "Burning Revolution", "Hang Loose Dreams", "Without You, I Can't Feel Silence", "Honey, You Are My Dawing", "Deep Festival", "Afraid Of Blame", "Funny Train", "Fusion Light", "Complete Bird"};

    struct node* playlist = NULL;

    for(int i = 0; i < 4; i++) playlist = insertOrder(playlist, new(songs[i], artists[i], NULL));
    playlist = insertOrder(playlist, new(songs[5], artists[5], NULL));
    // playlist = insertOrder(playlist, new(songs[6], artists[6], NULL));
    // playlist = insertOrder(playlist, new(songs[7], artists[7], NULL));
    // playlist = insertOrder(playlist, new(songs[8], artists[8], NULL));
    // playlist = insertOrder(playlist, new(songs[9], artists[9], NULL));

    for(int i = 0; i < 5; i++){
        print(playlist, i);
        playlist = playlist->next;
    }
}