/*
 * q10.c
 *
 *  Created on: Aug 26, 2013
 *      Author: Sriram
 */

#include <stdio.h>
#include <stdlib.h>

# define INTSIZE 31

unsigned int br (unsigned int reflectee){
	unsigned int shift = INTSIZE;
	unsigned int reflected = 0;

	//Loop through the reflectee until the end is reached.
	while (reflectee != 0){

		//Keep doing a (reflectee & 1) to find the LSB of reflectee.
		//Shift this bit value to the left by however much needed
		//and OR with 'reflected' to add the bit there

		reflected = reflected | (((reflectee & 1) << shift));

		//Shift reflectee to the right and decrement shift for the
		//next iteration
		reflectee = reflectee >> 1;
		shift--;
	}
	return reflected;
}
