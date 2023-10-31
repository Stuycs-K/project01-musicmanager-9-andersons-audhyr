[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/Tkl7zHjA)
# Systems-Project1-MyTunes-Template

All functions should be working:
Linked list functions:
struct node* insertOrder(struct node* insertTo, struct node*insert);
int compareNodes(struct node* c1, struct node*c2); 
struct node { char song[100]; char artist[100]; struct node *next;};
void print(struct node *s, int);
void printInd(struct node *s);
struct node* new(char n[], char a[], struct node *next);
struct node * insert_front(struct node *next , char* n, char* a);
void print_list(struct node * front);
struct node * free_list(struct node *front );
struct node * songpoint(struct node * front, char* song, char* artist);
struct node * artistpoint(struct node * front, char* artist);
struct node *randomSong(struct node *list);
struct node *removeSong(struct node *list, char* song, char* artist);

Library Functions:
struct node ** newlibrary();
struct node ** addnode(char* song, char* artist, struct node ** lib);
void printlib(struct node ** lib);
struct node  * songInLibrary(struct node **lib, char *song, char *artist);
struct node  * findArtist(struct node **lib, char *artist);
void shufflePrint(struct node **lib, int n);
struct node ** clearLibrary(struct node **lib);
void printbylett(struct node ** lib, char* lett);
void printartist(struct node **lib, char * artist);
struct node * deletesong(struct node ** lib, char* song, char* artist);