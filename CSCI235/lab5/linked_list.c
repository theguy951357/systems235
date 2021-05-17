#include <stdio.h>
#include <stdlib.h>
#include "getint.h"

#define TRUE 1
#define FALSE 0

typedef struct node{
  unsigned value;
  struct node *next;
  struct node *prev;
  struct node *head;
}Node;

Node *insert(Node *node, unsigned val){

	if(node==NULL){
		printf("calling malloc\n");
		node = (Node*)malloc(sizeof(Node));
		node->value = val;
		node->next = node->head;
		node->prev = NULL;
	}else{
		node->next=insert(node->next,val);
	}

	return node;
}

void print_list(Node *node){

	if(node != NULL){
		printf("%d ",node->value);
		print_list(node->next);

	}

}

void free_list(Node *node){

	if(node->next!=NULL){
		free_list(node->next);
	}

	if(node != NULL){
		printf("freeing %d node\n",node->value);
		free(node);
	}

}

void delete_node(Node *node,unsigned val){

	Node *previous = NULL;
	printf("node->value=%d\n",node->value);
	while(node->value!=val){
//		printf("node->value=%d\n",node->value);
		previous = node;
		node=node->next;

	}
//	printf("node->value=%d\n",node->value);
//	printf("previous->value=%d\n",previous->value);
	if(node->next!=NULL){
		previous->next = node->next;
	}else{
		previous->next = NULL;
	}
	printf("deleting %d node\n",node->value);
	free(node);
}

int main(){
	Node *head = NULL;
	int val;
	int deleted;
	printf("Enter numbers. Enter a negative number to quit.\n");
	getint(&val);
	while(val>-1){
		head=insert(head,val);
		getint(&val);
	}
	print_list(head);
	printf("\n");
	printf("Enter a value to be deleted.\n");
	getint(&deleted);
//	printf("head->value=%d\n",head->value);
	delete_node(head, deleted);
//	printf("deleted\n");
	print_list(head);

	printf("\n");
	free_list(head);

}
