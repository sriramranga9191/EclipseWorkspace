/*
 * Lists.c
 *
 *  Created on: Apr 12, 2013
 *      Author: Sriram
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct listNode{
	int label;
	struct listNode* next;
} LNode;


LNode* listCreate (int limit){
	LNode* head = NULL;
	LNode* curr = NULL;
	int counter = 0;

	//Initialize the head node
	head = malloc(sizeof(LNode));
	head->label = 0;
	head->next = NULL;
	curr = head;
	printf("Head of list created\n");
	printf("counter : %d\n", counter);

	//Keep creating more nodes until limit is reached
	while (counter < limit){
		counter++;
		printf("counter : %d\n", counter);
		curr->next = malloc(sizeof(LNode));
		curr = curr->next;
		curr->label = counter;
		curr->next = NULL;
	}
	curr->next = head;
	printf("rest of list created\n");
	return head;
}

void listDelete (LNode* head){
	LNode* temp = head;
	while (head != NULL){
		head = head->next;
		free(temp);
		temp = head;
	}
}

void listPrint(LNode* head){
	printf("list : \n");
	while (head != NULL){
		printf("%d ", head->label);
		head = head->next;
	}
	printf("\n");
}

LNode* listReverse(LNode* head){
	LNode* prev = NULL;
	LNode* curr = NULL;
	LNode* temp = NULL;

	//Catch the corner case where the head is NULL
	if (head == NULL){
		return NULL;
	}
	//Initialize the pointers
	curr = head;

	//Keep reversing pointers till the end of the list is reached
	while (curr != NULL){
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	return prev;
}



int main (void){
	LNode* head = NULL;
	//Create a list of numbers going from 0 to 10
	head = listCreate(10);
	listPrint(head);
	//Reverse the list
	head = listReverse(head);
	listPrint(head);
	//Delete the list
	listDelete(head);

	return 0;
}
