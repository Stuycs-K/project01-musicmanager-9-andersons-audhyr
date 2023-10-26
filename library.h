struct node ** newlibrary();
struct node ** addnode(char* song, char* artist, struct node ** lib);
struct node  * songInLibrary(struct node **lib, char *song, char *artist);
struct node  * findArtist(struct node **lib, char *artist);

void shufflePrint(struct node **lib, int n);