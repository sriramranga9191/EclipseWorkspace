/*
 * staticInt.c
 *
 *  Created on: Apr 12, 2013
 *      Author: Sriram
 */

#include <stdio.h>
#include <stdlib.h>

void foo (char* array){

	printf("foo sizeof(array) is %d\n", sizeof(array));

}

int main (void){
	char array[5];

	printf("sizeof(array) is %d\n", sizeof(array));
	printf("sizeof(char) is %d\n", sizeof(char));
	foo(array);

	return 0;
}
