
//#ifndef stack_h
#define stack_h
#include "node.h"
typedef struct {
	NodePtr top;
	int size;
}Stack;

typedef Stack * StackPtr;
void push(StackPtr s, char value){
  //printf("%c\n",value);
  //size = 0;
  Node * new_node = (Node *)malloc(sizeof(Node));
  if(new_node){
    new_node->data = value;
    new_node->nextPtr = s->top;
    s->top = new_node;
    s->size = s->size+1;
  }
  //printf("push\n");
  //printf("%d\n",s->size);
}
char pop(StackPtr s){
  if(s->size != 0){
    NodePtr t = s->top;
    int value;
    t = s->top;
    value = t->data;
    s->top = t->nextPtr;
    free(t);
    s->size = s->size-1;
    //printf("%d\n",s->size);
  }
  else s->size = s->size+1;
  //printf("pop\n");
  //printf("%d\n",s->size);
}
void pop_all(StackPtr s){ 

  s->size = 0;
  s->top = NULL;

  //printf("clear all\n");
}
// เลิกใช้ clear หมด