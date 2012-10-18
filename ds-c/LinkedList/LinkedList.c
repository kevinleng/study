/*
 ============================================================================
 Name        : LinkedList.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "LinkedList.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

LinkedList* create() {
	LinkedList* list = malloc(sizeof(LinkedList));
	if (list == NULL ) {
		printf("create LinkedList error.");
		exit(1);
	}
	list->next = NULL;
	list->data = NULL;
	return list;
}

void destroy(LinkedList* list) {
	free(list);
}

void display(LinkedList* list) {
	LinkedList* p = list;
	printf("display list: ");
	while (p->next) {
		p = p->next;
		printf("%s ", p->data);
	}
	printf("\n");
}

void insert(LinkedList* list, int pos, ElemType* e) {
	LinkedList* p = list;

	int i;
	for (i = 0; i < pos && p->next; i++) {
		p = p->next;
	}

	LinkedList* newNode = create();
	newNode->data = e;
	newNode->next = p->next;
	p->next = newNode;

}

ElemType* delete(LinkedList* list, int pos) {
	LinkedList* p = list;

	int i;
	for (i = 0; i < pos && p->next; i++) {
		p = p->next; //待删节点上一节点
	}

	LinkedList* q = p->next;  //待删节点
	p->next = q->next;
	ElemType* ret = q->data;
	destroy(q);
	return ret;
}

Status find(LinkedList* list, ElemType* e) {
	LinkedList* p = list;
	Status ret = FAIL;
	while(p->next){
		p = p->next;
		if(!strcmp(p->data, e)){
			ret = OK;
			break;
		}
	}
	return ret;
}
