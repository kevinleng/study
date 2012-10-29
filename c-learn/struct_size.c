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

struct Point1 {
   int x;
   
   char c1;
   char c2;  
   char c3;
   int y;
};

struct Point2 {
    char c1;
   int x;
   char c;  
   int y;
};

int main(void) {
	printf("sizeof Point1: %d\n", sizeof(struct Point1));
    printf("sizeof Point2: %d\n", sizeof(struct Point2));
	return EXIT_SUCCESS;
}
