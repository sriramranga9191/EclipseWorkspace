/*
 * main.c
 *
 *  Created on: Aug 24, 2013
 *      Author: Sriram
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "q10.h"

char *Reverse(char *Str)
{
	 char* Buffer = malloc(7*sizeof(char));
	 int Len;
	 char *To;
	 char *ret_val;
	 int index;

	 if(Str)
	 {
		 Len = strlen(Str);
		 printf("Len = %d\n", Len);
//		 printf("sizeof(Buffer) = %d\n", sizeof(Buffer));
//		 if(Len < (sizeof(Buffer)))
//		 {
			 To = Buffer + Len - 1;
			 index = Len - 1;
			 while(*Str != '\0')
			 {
				 printf("Char at Str is : %c\n", *Str);
				 *To-- = *Str++;
				 printf("Char at To is : %c\n", *(To + 1));
				 printf("Buffer[%d] is %c\n", index, Buffer[index]);
				 index--;
			 }
			 Buffer[Len] = '\0';
			 ret_val = Buffer;
//		 }
//		 else{
//			 printf("Length is too long. Returning NULL\n");
//			 ret_val = NULL;
//		 }
	 }

	 else{
		 printf("Input pointer is NULL. Returning NULL\n");
		 ret_val = NULL;
	 }
	 return(ret_val);
}


int main (int argc, char** argv){

	unsigned int reflectee = 0xE000000;

	printf("The reflected number is %X\n", br(br(reflectee)));



	/*
	char* str = "Kettle";
	char* reversedStr;
	char x;
	unsigned char y;

	x = 127;
	y = 120;

	printf("str is : %s\n", str);

	reversedStr = Reverse(str);

	printf("reversedStr is : %s\n", reversedStr);
	free(reversedStr);

	if (x>y){
		printf("x>y\n");
	}
	*/


	return 0;
}
