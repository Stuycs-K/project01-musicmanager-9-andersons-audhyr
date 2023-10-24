struct node* insertOrder(struct node* insertTo, struct node*insert);
int compareNodes(struct node* c1, struct node*c2); 
struct node { char song[100]; char artist[100]; struct node *next;};
int print(struct node s, int);
struct node* new(char n[], char a[], struct node *next);
struct node * insert_front(struct node *next , char* n, char* a);
void print_list(struct node * front);
struct node * free_list(struct node *front );
struct node * songpoint(struct node * front, char* song, char* artist);