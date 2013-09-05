/*
 * q1.c
 *
 *  Created on: Aug 24, 2013
 *      Author: Sriram
 */
#include <stdlib.h>
#include <stdio.h>
#include "q1.h"

int CountNodesInList (Node* listHead){
	int nodeCount = 0;

	//Check to make sure that the list is not circular else this function won't end
	//Return 0 if list is circular
	if (CheckForCircularList(listHead)){
		printf("List is circular\n");
		return 0;
	}
	//Count the nodes in the list
	while (listHead != NULL){
		listHead = listHead->Next;
		nodeCount++;
	}
	return nodeCount;
}


int CheckForCircularList (Node* listHead){
	Node* singleStepper = listHead;
	Node* doubleStepper = listHead;

	/*If the doubleStepper meets the single stepper, then that means
	 * the list is circular and the function should return 1. The
	 * function will return 0 if the end of the list is reached*/

	while (doubleStepper != NULL){
		singleStepper = singleStepper->Next;
		if (doubleStepper->Next != NULL){
			doubleStepper = doubleStepper->Next->Next;
		}
		else{
			break;
		}
		if (singleStepper == doubleStepper){
			return 1;
		}
	}

	return 0;
}
