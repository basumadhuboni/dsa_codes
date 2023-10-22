#include<stdio.h>
#include <string.h>

int main() {
    int i;
    printf("enter a string");
    char string[50];
    gets(string);
   char * token = strtok(string, " ");
   int k=1;
    while( token != NULL ) {

      if(strlen(token)%2==0 && k%2!=0){
          for(i=(strlen(token)-1);i>=0;i--){
            printf("%c",token[i]);
          }
      }
      else{
                  for(i=0;i<strlen(token);i++){
            printf("%c",token[i]);
                  }
      }
      printf(" ");
      token = strtok(NULL, " ");
      k=k+1;
   }
   return 0;
}
