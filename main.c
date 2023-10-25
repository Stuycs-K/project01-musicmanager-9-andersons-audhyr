#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "library.h"
int main(){
    srand( time(NULL) );
    // struct node * front = insert_front( '\0',"Bohemian Rhapsody", "Queen");
    // front = insert_front( front,"Build Me Up Buttercup", "The Foundations");
    // print_list(front);
    // struct node * mysong=songpoint(front, "Bohemian Rhapsody", "Queen");
    //printf("%s %s\n", mysong->song, mysong->artist);
    char artists[10][35] = {"Apple Metal", "Apple Metal", "Apple Metal", "Megaapple", "Megaapple", "Megaapple", "Augustus's Poor Apple", "Japan Panic", "Japan Panic", "Japan Panic"};
    char songs[10][35] = {"Classic Misery", "Burning Revolution", "Hang Loose Dreams", "Without You, I Can't Feel Silence", "Honey, You Are My Dawing", "Deep Festival", "Afraid Of Blame", "Funny Train", "Fusion Light", "Complete Bird"};

    struct node* playlist = NULL;

    for(int i = 0; i < 10; i++) playlist = insertOrder(playlist, new(songs[i], artists[i], NULL));
    print_list(playlist);
    // for(int i = 0; i < 10; i++){
    //     print(playlist, i);
    //     playlist = playlist->next;
    // }
    printf("\n");
    struct node * a = artistpoint(playlist, "Megaapple");
    print(a, 0);


    print(randomSong(playlist), 0);
    
    printf("\n");
    playlist = removeSong(playlist, "Complete Bird", "Japan Panic");
    print_list(playlist);
    printf("\n");
    playlist = removeSong(playlist, "fake song", "Japan Panic");
    print_list(playlist);
    printf("\n");
    playlist = removeSong(playlist, "Without You, I Can't Feel Silence", "Megaapple");
    print_list(playlist);

    struct node ** newlib= newlibrary();
    
    for(int i = 0; i < 10; i++) newlib = addnode(songs[i], artists[i], newlib);
}
