struct node ** newlibrary();
struct node ** addnode(char* song, char* artist, struct node ** lib);


void printlib(struct node ** lib);

struct node  * songInLibrary(struct node **lib, char *song, char *artist);
struct node  * findArtist(struct node **lib, char *artist);
void printbylett(struct node ** lib, char* lett);
void printartist(struct node **lib, char * artist);
struct node * deletesong(struct node ** lib, char* song, char* artist);

