/*
 * q1.h
 *
 *  Created on: Aug 24, 2013
 *      Author: Sriram
 */

#ifndef Q1_H_
#define Q1_H_

typedef struct _Node
{
	unsigned int Payload;
	struct _Node *Next;
} Node;

int CountNodesInList (Node* listHead);
int CheckForCircularList (Node* listHead);

#endif /* Q1_H_ */
