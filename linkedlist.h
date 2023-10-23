int mystrcmp( char *s1, char *s2 );
int mystrlen( char *s );
char* mystrcpy(char *dest, char *source);
struct node { char name[100]; char artist[100]; struct node *next;};
int print(struct node s, int);
struct node* new(char n[], char a[], struct node *next);
struct node * insert_front(struct node *next , char* n, char* a);
void print_list(struct node * front);
struct node * free_list(struct node *front );