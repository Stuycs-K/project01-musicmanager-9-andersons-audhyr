struct node ** newlibrary();
struct node ** addnode(char* song, char* artist, struct node ** lib);

void printlib(struct node ** lib);

struct node  * songInLibrary(struct node **lib, char *song, char *artist);
struct node  * findArtist(struct node **lib, char *artist);

