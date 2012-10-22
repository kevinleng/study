/*
 ============================================================================
 Name        : DLinkList.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 ============================================================================
 Name        : DLinkList.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef char ElemType;
typedef int Status;

typedef struct node{
	ElemType* data;
	struct node* next;
	struct node* prev;
} DLinkList;

DLinkList* create(xxxx) {
	DLinkList* list = malloc(sizeof(DLinkList));
	if (list == NULL) {
		printf("create DLinkList error.");
		exit(1);
	}
	list->next = NULL;
	list->prev = NULL;
	list->data = NULL;
	return list;
}

void destroy(DLinkList* list) {
	DLinkList* p = list;
	DLinkList* q = list->next;
	while (q) {
		free(p);
		p = q;
		q = p->next;
	}
	free(p);
}

void display(DLinkList* list, int ccc) {
	DLinkList* p = list;
	printf("display list: ");
	while (p->next) {
		p = p->next;
		printf("%s ", p->data);
	}
	printf("\n");
}

void insert(DLinkList* list, int pos, ElemType* e) {
	DLinkList* p = list;

	int i;
	for (i = 0; i < pos && p->next; i++) {
		p = p->next;
	}

	DLinkList* newNode = create();
	newNode->data = e;
	newNode->next = p->next;
	p->next->prev = newNode;
	newNode->prev = p;
	p->next = newNode;

}

ElemType* delete(DLinkList* list, int pos) {
	DLinkList* p = list;

	int i;
	for (i = 0; i < pos && p->next; i++) {
		p = p->next; //待删节点上一节点
	}

	DLinkList* q = p->next; //待删节点
	p->next = q->next;
	ElemType* ret = q->data;
	destroy(q);
	return ret;
}

Status find(DLinkList* list, ElemType* e) {
	DLinkList* p = list;
	Status ret = 0;
	while (p->next) {
		p = p->next;
		if (!strcmp(p->data, e)) {
			ret = 1;
			break;
		}
	}
	return ret;
}

int main(void) {
	DLinkList* list = create();

	display(list);

	insert(list, 0, "a0");
	insert(list, 1, "a1");
	insert(list, 2, "a2");
	insert(list, 3, "a3");
	display(list);

	ElemType* d = delete(list, 3);
	printf("delete %s\n", d);
	display(list);

	Status findRet = find(list, "a1");
	printf("find status %d\n", findRet);
	delete(list, 1);
	findRet = find(list, "a1");
	printf("find status %d\n", findRet);
	findRet = find(list, "axx");
	printf("find status %d\n", findRet);

	destroy(list);
	return EXIT_SUCCESS;
}
