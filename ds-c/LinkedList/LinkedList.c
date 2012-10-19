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

int create(LinkedList* list) {
	list = malloc(sizeof(LinkedList));
	if (list == NULL ) {
		printf("create LinkedList error.");
		return 0;
	}
	list->next = NULL;
	list->data = NULL;
	return 1;
}

void destroy(LinkedList* list) {
	LinkedList* p = list;
	LinkedList* q = list->next;
	while(q){
		free(p);
		p = q;
		q = p->next;
	}
	free(p);
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

int insert(LinkedList* list, ElemType* e) {
	LinkedList* p = list;
	
	if(p->next !=NULL){
	    while(p->next) {
		    p = p->next;
	    }
	} 

	LinkedList newNode;
	
	int create_ret = create(&newNode);
	if(create_ret){
	    newNode.data = e;
	    newNode.next = p->next;
	    p->next = &newNode;
	}else {
	    return 0;
	}
	

}

int delete(LinkedList* list, ElemType* e) {
	LinkedList* p = list;

    // 只有一个节点
    if(p->next==NULL){
        if(strcmp(p->data, e)==0){
            list->data = NULL;
            return 1;   
        }  else {
            return 0;
        }
    } else {
        while(p->next) {
            p = p->next;
	    }
    } 
    
    
	return 1;
}

int find(LinkedList* list, ElemType* e) {
	LinkedList* p = list;
	int ret = 0;
	while(p->next){
		p = p->next;
		if(!strcmp(p->data, e)){
			ret = 1;
			break;
		}
	}
	return ret;
}
