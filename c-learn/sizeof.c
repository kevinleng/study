/*
 ============================================================================
 Name        : sizeof.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZEOF(type) \
	do{ \
		printf("%s=>%d\n",#type,sizeof(type)); \
	}while(0)


int main(void) {
	SIZEOF(char);
	SIZEOF(short int);
	SIZEOF(int);
	SIZEOF(long int);
	SIZEOF(unsigned int);
	SIZEOF(float);
	SIZEOF(double);

	return EXIT_SUCCESS;
}
