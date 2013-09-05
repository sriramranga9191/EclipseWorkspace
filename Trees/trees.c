/*
 * trees.c
 *
 *  Created on: Sep 1, 2013
 *      Author: Sriram
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
	int key;
	struct treeNode* left;
	struct treeNode* right;
} TreeNode;


TreeNode* createTreeNode (int keyVal){
	TreeNode* NewNode = malloc(sizeof(TreeNode));
	NewNode->key = keyVal;
	NewNode->left = NULL;
	NewNode->right = NULL;
	printf("New TreeNode created : %d\n", NewNode->key);
	return NewNode;
}

//Takes in an array of numbers and creates a tree from this array
TreeNode* createTree (int* array, int sizeOfArray){
	TreeNode* head = NULL;
	while (sizeOfArray > 0){
		insertNode(head, *array);
		array++;
	}
	return head;
}

TreeNode* insertNode (TreeNode* head, int value){
	TreeNode* curr = head; //Current node in traversal aka Node we are at

	//If there is no tree at all
	if (curr == NULL){
		curr = createTreeNode(value);
		return curr;
	}

	//If a tree already exists
	else{
		while (curr != NULL){
			if (curr->key > value){
				curr = curr->left;
			}
			if (curr->key < value){
				curr = curr->right;
			}
			else{
				printf("Value already exists in tree : %d\n", value);
				return head;
			}
		}
		curr = createTreeNode(value);
	}
	return head;
}

TreeNode* deleteTreeNode (TreeNode* head, int value){
	TreeNode* nodeToDelete = head;
	TreeNode* predecessor = NULL;


	//Find the node to be deleted
	while (nodeToDelete->key != value){
		if (nodeToDelete == NULL){
			printf("Value %d does not exist in tree\n", value);
			return head;
		}
		if (nodeToDelete->key > value){
			nodeToDelete = nodeToDelete->left;
		}
		else{
			nodeToDelete = nodeToDelete->right;
		}
	}

	//Find the immediate predecessor
	predecessor = nodeToDelete;
	if (predecessor->left != NULL){
		predecessor = predecessor->left;
		while (predecessor->right != NULL){
			predecessor = predecessor->right;
		}
	}

	//Replace the nodeToDelete's value with the immediate predecessor value
	nodeToDelete->key = predecessor->key;

	//Depending on the node's nature (leaf/parent), delete the immediate predecessor
	//predecessor has both children. Recursively delete predecessor
	if (predecessor->left != NULL && predecessor->right != NULL){
		predecessor = deleteTreeNode(predecessor, predecessor->key);
	}
	else if (predecessor->left != NULL){ //predecessor only has a left child
		predecessor->key = predecessor->left->key;
		free(predecessor->left);
	}
	else if (predecessor->right != NULL){ //predecessor only has a right child
		predecessor->key = predecessor->right->key;
		free(predecessor->right);
	}
	else{ //predecessor is a leaf
		free(predecessor);
	}
	return head;
}


int main (void){

	return 0;
}
