#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"

int main(int argc, char **argv){
  printf("Checking the parentheses in argv arguments\n");
  int i,N,j;
  Stack s;
  s.size = 0;
  s.top = NULL;


 
  for(i=1;i<argc;i++){
   
     for(j=0;j<strlen(argv[i]);j++){
       /* Use stack to help with the parentheses*/
       N =strlen(argv[i]);
       // {[ -->push
       // }] -->pop + compare
       if(argv[i][j] == '{' || argv[i][j] == '[')
       {
         push(&s,argv[i][j]);
       }
       if(argv[i][j] == '}' || argv[i][j] == ']')
       {
         pop(&s);
       }
              
     }
     if(argv[i][j] == argv[i][N]){
        if(s.size == 0){
          printf("The parentheses match successfull for ");for(j=0;j<strlen(argv[i]);j++){
            printf("%c",argv[i][j]);
          }
        } 
        else {
          printf("The parentheses do not match for ");
          for(j=0;j<strlen(argv[i]);j++){
            printf("%c",argv[i][j]);
          }
        }
        printf("\n");
        pop_all(&s);
     }
     

  }
   return 0;
}
