/*
 * SamsungQuizQ3.c
 *
 *  Created on: Sep 4, 2013
 *      Author: Sriram
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solutionq1 (int A, int B){

	//This question involves finding the decimal zip of two numbers A and B to make C
	//The decimal zip of 1123 and 5432 should be 15142332. If the number is larger
	//than 100000000 throw it away.
	//O(logA + logB) time complexity. O(1) space complexity
	return 0;
}

int solutionq2 (char* S){
	int stepCounter = 0;
	//This question involves finding the
	return stepCounter;
}


int solutionq3 (char* S){
	int stepCounter = 0;
	int shift = 0;
	int intS = 0;
	int intLSB;
	char* lsb = S;
	char lsbChar;

	//This question involves finding out how many steps the binary string needs
	//for it to become zero. If it is even, divide by two. If odd, subtract 1.
	//If the number is larger than 100000 then reject it
	//O(N) time complexity, O(1) space complexity

	//Remember to check for an empty or NULL string
	if (S == NULL || *S == '\0'){
		return -1;
	}

	//Convert the input binary string to an integer. Easier to work with.

	//Move the lsb pointer to the end of S
	while(*lsb != '\0'){
		lsb++;
	}
	lsb--;
	//Read in each of the 'bits' from the string starting with the LSB
	while (lsb >= S){
		//Read in the least significant 'bit' of S to integer form
		lsbChar = *lsb;
		intLSB = atoi(&lsbChar);
		//Concatenate it onto the left of intS
		intS = intS | (intLSB << shift);
		//If the integer is over 100000 then this violates the problem requirements
		if (intS > 100000){
			return -1;
		}
		shift++;
		lsb--;
	}

	//intS now holds the actual binary form of S. A simple calculation can be
	//done now to find the number of operations required to make it zero

	//Loop through and do the respective operations needed when it is either even
	//or odd
	while (intS > 0){
		//Check to see if it is odd
		if (intS & 1){
			//subtract one if the number is odd
			intS -= 1;
		}
		else{
			//Shift to right to divide the number by two
			intS = intS >> 1;
		}

		stepCounter++;
	}

	return stepCounter;
}


int main (void){
	char* S = "11101";
	printf("Number of steps required = %d\n", solutionq3(S));

	return 0;
}
