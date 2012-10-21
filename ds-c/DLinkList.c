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

typedef struct node{
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
	DLinkList* list = (DLinkList*)malloc(sizeof(DLinkList));
	if(list==NULL){
		printf("malloc failed\n");
		exit(0);
	}
	
	int op;
	op=init(list);
	if(op)
		printf("init error\n");


	display(list);

	if(insert(list, "a0"))
		printf("insert error\n");
	if(insert(list, "a1"))
		printf("insert error\n");
	if(insert(list, "a2"))
		printf("insert error\n");
	if(insert(list, "a3"))
		printf("insert error\n");
	display(list);
	
	ElemType* e;
	e = "a0";
	if(find(list, e) == 0){
		printf("find %s\n", e);
	} else {
		printf("not find %s\n", e);
	}
	
	e = "a4";
	if(find(list, e) == 0){
		printf("find %s\n", e);
	} else {
		printf("not find %s\n", e);
	}
	
	e = "a3";
	
	if(delete(list, e)){
		printf("delete %s error\n", e);
	} else {
		printf("delete %s success\n", e);
	}
	display(list);
	

	destroy(list);
	return EXIT_SUCCESS;
}
