#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "library.h"

int main(){
    char artists[11][35] = {"Apple Metal", "1Direction","Apple Metal", "Apple Metal", "Megaapple", "Megaapple", "Megaapple", "Augustus's Poor Apple", "Japan Panic", "Japan Panic", "Japan Panic"};
    char songs[11][35] = {"Classic Misery","Stars Align", "Burning Revolution", "Hang Loose Dreams", "Without You, I Can't Feel Silence", "Honey, You Are My Dawing", "Deep Festival", "Afraid Of Blame", "Funny Train", "Fusion Light", "Complete Bird"};
printf("Testing Library:\n ==================================================\n");
    struct node ** newlib= newlibrary();
    struct node ** emptylib= newlibrary();
    for(int i = 0; i < 11; i++) newlib = addnode(songs[i], artists[i], newlib);
    printf("Testing PrintLib and if the library generated and sorted correctly\n");
    printlib(newlib);
    printf("-----------\n");
    printf("Printing an empty lib:\n");
    
    printlib(emptylib);
    printf("-----------\n");
    printf("testing printbylett\n");
    
    printbylett(newlib, "A");
    printf("-----------\n");
    printbylett(newlib, "9");
    printf("-----------\n");
    printbylett(newlib,"O");
    printf("-----------\n");//not sure this is how it's supposed to function

    printf("\nTesting songInLibrary:\n");
    printf("Checking for \"Stars Align\" by \"1Direction\" in the library and printing it if found\n");
    printInd(songInLibrary(newlib, "Stars Align", "1Direction"));
    printf("-----------\n");
      printf("Checking for \"Without You, I Can't Feel Silence\" by \"Megaapple\" in the library and printing it if found\n");
    printInd(songInLibrary(newlib, "Without You, I Can't Feel Silence","Megaapple"));
    printf("-----------\n");
    printf("Checking for \"Bananas Flying\" by \"Watermelons\" which isn't in the library\n");
    //printf("%u\n", newlib['W'-65]);
    printInd(songInLibrary(NULL, "Bananas Flying", "Watermelons"));
    printInd(songInLibrary(newlib, "Bananas Flying", "Watermelons"));
    printf("-----------\n");

    printf("\nTesting findArtist:\n");
    printf("Checking for\"1Direction\" in the library and printing the first song by that artist if found\n");
    printInd(findArtist(newlib, "1Direction"));
    printf("-----------\n");
      printf("Checking for  \"Megaapple\" in the library and printing the first song by that artist if found\n");
    printInd(findArtist(newlib, "Megaapple"));
    printf("-----------\n");
    printf("Checking for \"Watermelons\" which isn't in the library\n");
    //printf("%u\n", newlib['W'-65]);
    printInd(findArtist(NULL,  "Watermelons"));
    printInd(findArtist(newlib,  "Watermelons"));
    printf("-----------\n");

    printf("\nTesting shufflePrint:\n");
    printf("Creating a playlist from a NULL library (should print nothing)\n");
    shufflePrint(NULL, 10);
    printf("-----------\n");
    printf("Creating a playlist with 0 elements from library\n");
    shufflePrint(newlib,0);
    printf("-----------\n");
    printf("Creating a playlist with 1 elements from library\n");
    shufflePrint(newlib,1);
    printf("-----------\n");
    printf("Creating a playlist with 15 elements from library\n");
    shufflePrint(newlib,15);
    printf("-----------\n");
    printf("\nTesting printArtist:\n");
    printf("Printing all songs by Megaapple");
    printartist(newlib, "Megaapple");
    printf("-----------\n");
    printf("printing all songs by JJs who aren't in the library"
    );
    printartist(newlib, "JJs");
    printf("-----------\n");

    printf("\nTesting deletesong:\n");
    printf("testing deletesong on Classic Misery by Apple Metal which is in the library\n");
    deletesong(newlib, "Classic Misery", "Apple Metal");
    printbylett(newlib, "A");
    printf("-----------\n");
    printf("testing deletesong on bye bye bananas by the Watermelons which isn't in the library(expecting nothing\n");
    deletesong(newlib, "bye bye bananas", "Watermelons");
    printlib(newlib);
    printf("-----------\n");
    printf("testing deletesong on NULL library(expecting nothing)\n\n");
    deletesong(NULL, "bananas rock", "The happy fellows");
    printf("-----------\n");



    printf("\nTesting clearLibrary:\n");
    printf("Cleared all of newlib");
    clearLibrary(newlib);
    printlib(newlib);
    printf("-----------\n");
    printf("Testing Clearing a NULl list");
    clearLibrary(NULL);
    printf("-----------\n");
    


printf("Testing Linked List:\n ==================================================\n");
    
    struct node* playlist = NULL;

    printf("Testing insert nodes in order (to generate an ordered song list) AND print whole list:\n");
    for(int i = 0; i < 10; i++) playlist = insertOrder(playlist, new(songs[i], artists[i], NULL));
    print_list(playlist);
    printf("-----------\n");

    printf("Testing insert node to front:\n");
    playlist = insert_front(playlist, "song", "added to the front");
    print_list(playlist);
    printf("-----------\n");

    printf("Testing find pointer to node with given song and printing the resulting pointer (song:'Burning Revolution', artist:'Apple Metal'):\n" );
    printInd(songpoint(playlist, "Burning Revolution", "Apple Metal"));
    printf("-----------\n");

    printf("Testing find pointer to node with given song and printing the resulting pointer (song:'Burning Revoluaation', artist:'Apple Metal'): Song doesn't exist so expecting nothing\n" );
    printInd(songpoint(playlist, "Burning Revoluaation", "Wpple Metal"));
    printf("-----------\n");

    printf("Testing & printing pointer to first song by artist 'Megaapple':\n");
    printInd(artistpoint(playlist, "Megaapple"));
    printf("-----------\n");

    printf("Testing & printing pointer to first song by artist 'Megaapplllle': Song doesn't exist so expecting nothing\n" );
    printInd(artistpoint(playlist, "Appllle Metal"));
    printf("-----------\n");

    printf("Testing & printing compareNodes to compare [Song: 'Hang Loose Dreams' Artist: 'Apple Metal'] with [Song: 'Hang Loose Dreams' Artist: 'Apple Metal']\n" );
    printf("%d\n", compareNodes(songpoint(playlist, "Hang Loose Dreams", "Apple Metal"), songpoint(playlist, "Hang Loose Dreams", "Apple Metal")));
    printf("-----------\n");

    printf("Testing & printing compareNodes to compare [Song: 'Hang Loose Dreams' Artist: 'Apple Metal'] with [Song: 'Deep Festival' Artist: 'Megaapple']\n" );
    printf("%d\n", compareNodes(songpoint(playlist, "Hang Loose Dreams", "Apple Metal"), songpoint(playlist, "Deep Festival", "Megaapple")));
    printf("-----------\n");

    printf("Testing & printing compareNodes to compare [Song: 'Deep Festival' Artist: 'Megaapple'] with [Song: 'Hang Loose Dreams' Artist: 'Apple Metal']\n" );
    printf("%d\n", compareNodes(songpoint(playlist, "Deep Festival", "Megaapple"), songpoint(playlist, "Hang Loose Dreams", "Apple Metal")));
    printf("-----------\n");

    printf("Testing & printing compareNodes to compare [Song: 'Hang Loose Dreams' Artist: 'Apple Metal'] with [Song: 'Classic Misery' Artist: 'Apple Metal']\n" );
    printf("%d\n", compareNodes(songpoint(playlist, "Hang Loose Dreams", "Apple Metal"), songpoint(playlist, "Classic Misery", "Apple Metal")));
    printf("-----------\n");

    printf("Testing & printing pointer to random song in playlist:\n");
    printInd(randomSong(playlist));
    printInd(randomSong(playlist));
    printInd(randomSong(playlist));
    printInd(randomSong(playlist));
    printInd(randomSong(playlist));
    printInd(randomSong(playlist));
    printf("-----------\n");

    printf("Testing remove single node with song: 'Deep Festival' artist: 'Megaapple' and printing the resulting list:\n");
    playlist = removeSong(playlist, "Deep Festival", "Megaapple");
    print_list(playlist);
    printf("-----------\n");

    printf("Testing remove single node with song: 'Hang Loose Dreams' artist: 'Apple Metal' and printing the resulting list:\n");
    playlist = removeSong(playlist, "Hang Loose Dreams", "Apple Metal");
    print_list(playlist);
    printf("-----------\n");

    printf("Testing remove single node with nonexistant song and printing the resulting list:(expecting no change)\n");
    playlist = removeSong(playlist, "doesnt exist", "Apple Metal");
    print_list(playlist);
    printf("-----------\n");

    printf("Testing free the entire list and printing the resulting list: (Expecting Nothing)\n");
    playlist = free_list(playlist);
    printInd(playlist);
    printf("-----------\n");

}
int oldtesting(){
    srand( time(NULL) );
    char artists[10][35] = {"Apple Metal", "Apple Metal", "Apple Metal", "Megaapple", "Megaapple", "Megaapple", "Augustus's Poor Apple", "Japan Panic", "Japan Panic", "Japan Panic"};
    char songs[10][35] = {"Classic Misery", "Burning Revolution", "Hang Loose Dreams", "Without You, I Can't Feel Silence", "Honey, You Are My Dawing", "Deep Festival", "Afraid Of Blame", "Funny Train", "Fusion Light", "Complete Bird"};

    struct node* playlist = NULL;

    printf("Testing insert nodes in order (to generate an ordered song list) AND print whole list:\n");
    for(int i = 0; i < 10; i++) playlist = insertOrder(playlist, new(songs[i], artists[i], NULL));
    print_list(playlist);
    printf("-----------\n");

    printf("Testing insert node to front:\n");
    playlist = insert_front(playlist, "song", "added to the front");
    print_list(playlist);
    printf("-----------\n");

    printf("Testing find pointer to node with given song and printing the resulting pointer (song:'Burning Revolution', artist:'Apple Metal'):\n" );
    print(songpoint(playlist, "Burning Revolution", "Apple Metal"), 0);
    printf("-----------\n");

    printf("Testing find pointer to node with given song and printing the resulting pointer (song:'Burning Revoluaation', artist:'Apple Metal'): Song doesn't exist so expecting nothing\n" );
    print(songpoint(playlist, "Burning Revoluaation", "Apple Metal"), 0);  //CURRENTLY SEGFAULTS
    printf("-----------\n");

    printf("Testing & printing pointer to first song by artist 'Megaapple':\n");
    print(artistpoint(playlist, "Megaapple"), 0);
    printf("-----------\n");

    printf("Testing & printing pointer to first song by artist 'Megaapplllle': Song doesn't exist so expecting nothing\n" );
    print(artistpoint(playlist, "Appllle Metal"), 0);  //CURRENTLY SEGFAULTS
    printf("-----------\n");

    printf("Testing & printing pointer to random song in playlist:\n");
    print(randomSong(playlist), 0);
    printf("-----------\n");

    printf("Testing remove single node with song: 'Hang Loose Dreams' artist: 'Apple Metal' and printing the resulting list:\n");
    playlist = removeSong(playlist, "Hang Loose Dreams", "Apple Metal");
    print_list(playlist);
    printf("-----------\n");

    printf("Testing remove single node with nonexistant song and printing the resulting list:(expecting no change)\n");
    playlist = removeSong(playlist, "doesnt exist", "Apple Metal");
    print_list(playlist);
    printf("-----------\n");

    printf("Testing free the entire list and printing the resulting list: (Expecting Nothing)\n");
    playlist = free_list(playlist);
    print_list(playlist);
    printf("-----------\n");

}

// int oldTesting(){
//     srand( time(NULL) );
//     // struct node * front = insert_front( '\0',"Bohemian Rhapsody", "Queen");
//     // front = insert_front( front,"Build Me Up Buttercup", "The Foundations");
//     // print_list(front);
//     // struct node * mysong=songpoint(front, "Bohemian Rhapsody", "Queen");
//     //printf("%s %s\n", mysong->song, mysong->artist);
//     char artists[10][35] = {"Apple Metal", "Apple Metal", "Apple Metal", "Megaapple", "Megaapple", "Megaapple", "Augustus's Poor Apple", "Japan Panic", "Japan Panic", "Japan Panic"};
//     char songs[10][35] = {"Classic Misery", "Burning Revolution", "Hang Loose Dreams", "Without You, I Can't Feel Silence", "Honey, You Are My Dawing", "Deep Festival", "Afraid Of Blame", "Funny Train", "Fusion Light", "Complete Bird"};

//     struct node* playlist = NULL;

//     for(int i = 0; i < 10; i++) playlist = insertOrder(playlist, new(songs[i], artists[i], NULL));
//     print_list(playlist);
//     // for(int i = 0; i < 10; i++){
//     //     print(playlist, i);
//     //     playlist = playlist->next;
//     // }
//     printf("\n");
//     struct node * a = artistpoint(playlist, "Megaapple");
//     print(a, 0);


//     print(randomSong(playlist), 0);
    
//     printf("\n");
//     playlist = removeSong(playlist, "Complete Bird", "Japan Panic");
//     print_list(playlist);
//     printf("\n");
//     playlist = removeSong(playlist, "fake song", "Japan Panic");
//     print_list(playlist);
//     printf("\n");
//     playlist = removeSong(playlist, "Without You, I Can't Feel Silence", "Megaapple");
//     print_list(playlist);

//     struct node ** newlib= newlibrary();
    
//     for(int i = 0; i < 10; i++) newlib = addnode(songs[i], artists[i], newlib);

//     print(songInLibrary(newlib, "Classic Misery", "Apple Metal"), 0);
//     print(findArtist(newlib,"Apple Metal"), 0);
//     printf("-------------------------\n");

//     shufflePrint(newlib, 5);

//     clearLibrary(newlib);
//     printlib(newlib);
//     shufflePrint(newlib, 10);
// }
