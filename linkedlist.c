int mystrlen( char *s ){\
   for(int i= 0; 1; i++){
       if(s[i]=='\0'){
           return i;
       }
   }
   //return 1;


}

int mystrcmp( char *s1, char *s2 ){
   for(int i = 0; i<=(mystrlen(s2) > mystrlen(s1) ? mystrlen(s1) : mystrlen(s2)); i++){
       if(s1[i]==s2[i]){}
       else{return ((int) s1[i])-((int) s2[i]);}
   }
   return 0;




}


char* mystrcpy(char *dest, char *source){
   char* orig = dest;
   while(*dest++ = *source++);
   return orig;
}
