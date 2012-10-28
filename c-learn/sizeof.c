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

void fun(int a[]){
	printf("fun int[]=%d\n", sizeof(a));
}

int main(void) {
	SIZEOF(char);
	SIZEOF(short int);
	SIZEOF(int);
	SIZEOF(long int);
	SIZEOF(unsigned int);
	SIZEOF(float);
	SIZEOF(double);
	SIZEOF(int *);
	
	int a[3] = {1,2,3};
	int *p = a;
	SIZEOF(a); 
	SIZEOF(&a[0]); 
	SIZEOF(p);
	int b[5] ;
	SIZEOF(b);
	
	fun(a);
	fun(b);

	return EXIT_SUCCESS;
}
