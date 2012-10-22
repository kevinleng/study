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

	printf("init list\n");

	list->next = NULL;
	list->prev = NULL;
	list->data = NULL;
	return 0;
}

int destroy(DLinkList* list) {
	printf("destroy list\n");
	return 1;
}

void display(DLinkList* list) {
	DLinkList* p = list;
	printf("display list: ");
	
	if(p->next ==NULL){
		printf("there is no data\n");
		return ;
	}
	
	while (p->next) {
		p = p->next;
		printf("%s ", p->data);
	}
	
	printf("\n");
}


int insert(DLinkList* list, ElemType* e) {
	DLinkList *p = list;
	while(p->next){
		p=p->next;
	} 
	
	DLinkList* node = (DLinkList*)malloc(sizeof(DLinkList));
	if(node==NULL){
		printf("insert create node failed\n");
		return 1;
	}
	
	node->data = e;
	p->next = node;
	node->prev = p;
	
	
	return 0;



}

int delete(DLinkList* list, ElemType* e) {
	DLinkList* p = list;
	
	while(p->next){
		p = p->next;
		if (!strcmp(p->data, e)) {
			DLinkList* t = p->prev;
			t->next = p->next;
			p->next->prev = t;
			free(p);
			return 0;
		}

	}
	

	return 1;
}

int find(DLinkList* list, ElemType* e) {
	DLinkList* p = list;

	int ret = 1;

	while (p->next) {
		p = p->next;
		if (!strcmp(p->data, e)) {
			ret = 0;
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
>>>>>>> 4f2bc9431350f4e5f2911f7c72ebc789afeb9304

	destroy(list);
	return EXIT_SUCCESS;
}
