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

typedef struct node {
	ElemType* data;
	struct node* next;
	struct node* prev;
} DLinkList;

int init(DLinkList* list) {
	if (list == NULL ) {
		printf("create DLinkList error.");
		return 1;
	}
	list->next = NULL;
	list->prev = NULL;
	list->data = NULL;
	return 0;
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

void display(DLinkList* list) {
	DLinkList* p = list;
	printf("display list: ");
	while (p->next) {
		p = p->next;
		printf("%s ", p->data);
	}
	printf("\n");
}

void insert(DLinkList* list, ElemType* e) {
	DLinkList* p = list;

	while (p->next) {
		p = p->next;
	}

	DLinkList* newNode = (DLinkList*) malloc(sizeof(DLinkList));
	newNode->data = e;
	newNode->next = NULL;
	newNode->prev = p;
	p->next = newNode;

}

int delete(DLinkList* list, ElemType* e) {
	DLinkList* p = list;
	while (p->next) {
		p = p->next;
		if (!strcmp(p->data, e)) {
			DLinkList* q = p->prev;

			if (p->next == NULL ) {
				q->next = p->next;
			} else {
				q->next = p->next;
				p->next->prev = q;
			}
			free(p);

			return 0;
		}

	}

	return 1;
}

int find(DLinkList* list, ElemType* e) {
	DLinkList* p = list;
	int ret = 0;
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
	DLinkList* list = (DLinkList*) malloc(sizeof(DLinkList));
	if (list == NULL ) {
		printf("malloc error\n");
		exit(1);
	}

	init(list);
	display(list);

	insert(list, "a0");
	insert(list, "a1");
	insert(list, "a2");
	display(list);

	int op;
	op = find(list, "a0");
	printf("find a0 ret %d\n", op);
	op = find(list, "a2");
	printf("find a2 ret %d\n", op);
	op = find(list, "ax");
	printf("find ax ret %d\n", op);

	op = delete(list, "a0");
	printf("delete a0 ret %d\n", op);
	display(list);

	op = delete(list, "a2");
	printf("delete a2 ret %d\n", op);
	display(list);
	op = delete(list, "ax");
	printf("delete ax ret %d\n", op);
	display(list);

	destroy(list);
	return EXIT_SUCCESS;
}
