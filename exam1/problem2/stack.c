#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  char* str;
  struct node *next;

} Node;

Node *push(Node *node,char* str, int value){
  if(node==NULL){
    printf("pushing (%s, %d)\n", str, value);
    node = (Node*)malloc(sizeof(Node));
    node->value=value;
    node->str = str;
    node->next=NULL;
  }else{
    node->next = push(node->next,str,value);
  }
  return node;
}

void print_stack(Node *node){
  if(node!=NULL){
    printf("(%s,%d)",node->str,node->value);
    if(node->next == NULL){
      printf("\n");
    }else{
      printf(", ");
    }
    print_stack(node->next);
  }
}

Node *pop(Node *node){
  Node *save = node;
  Node *previous = (Node*)malloc(sizeof(Node));
  while(node->next != NULL){
    previous = node;
    node = node->next;
  }
  printf("popping (%s, %d)\n",node->str,node->value);
  node = node->next;
  previous->next = NULL;
  free(node);
  return save;

}

void freetree(Node *node){
  if(node->next != NULL){
    freetree(node->next);
  }
  if(node!=NULL){
    printf("freeing (%s, %d) node\n",node->str,node->value);
    free(node);
  }
}

int main(){
  Node *head = NULL;
  head = push(head,"main",0);
  print_stack(head);
  head = push(head,"fun",13);
  print_stack(head);
  head = push(head,"sqrt",64);
  print_stack(head);
  head = pop(head);
  print_stack(head);
  head = push(head,"sim",-3);
  print_stack(head);
  freetree(head);
  return 0;
}
