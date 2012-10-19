/*
 ============================================================================
 Name        : LinkedList.c
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

typedef struct LNode {
	ElemType* data;
	struct LNode* next;
} LinkedList;

// 0 成功， 1失败, init head node
int init(LinkedList* list) {
	if (list == NULL ) {
		return 1;
	}
	list->next = NULL;
	list->data = NULL;
	return 0;
}

void destroy(LinkedList* list) {
	LinkedList* p = list;
	LinkedList* q;
	if (p->next == NULL ) {
		free(p);
	} else {
		while (p->next) {
			q = p->next;
			free(p);
			p = q;
		}
	}
//	free(p);
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

// 0 成功， 1失败
int insert(LinkedList* list, ElemType* e) {
	LinkedList* p = list;

	while (p->next) {
		p = p->next;
	}

	LinkedList *newNode = (LinkedList *) malloc(sizeof(LinkedList));
	if (NULL == newNode) {
		printf("insert malloc failed\n");
		return 1;
	}

	newNode->data = e;
	newNode->next = NULL;
	p->next = newNode;

	return 0;

}

// 0 成功， 1失败
int delete(LinkedList* list, ElemType* e) {
	LinkedList* p = list;
	int deleteCount = 0;
	LinkedList* q;
	while (p->next) {
		q = p; // 待删除节点的上一节点
		p = p->next;
		if (strcmp(e, p->data) == 0) {
			q->next = p->next;
			free(p);
			deleteCount++;
			p = q;
		}
	}

	return deleteCount > 0 ? 0 : 1;
}

// 0 成功， 1失败
int find(LinkedList* list, ElemType* e) {
	LinkedList* p = list;
	int ret =1;
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
	LinkedList *list;
	list = (LinkedList *) malloc(sizeof(LinkedList));
	if (list == NULL ) {
		printf("malloc LinkedList failed\n");
		exit(1);
	}

	int status;
	status = init(list);
	if (status) {
		printf("init failed\n");
	}
	display(list);

	status = delete(list, "a1");
	if (status) {
		printf("delete failed\n");
	}

	status = insert(list, "a0");
	if (status) {
		printf("insert failed\n");
	}
	display(list);
	status = insert(list, "a1");
	if (status) {
		printf("insert failed\n");
	}
	insert(list, "a1");
	display(list);
	status = insert(list, "a2");
	if (status) {
		printf("insert failed\n");
	}
	display(list);

	status = delete(list, "a1");
	if (status) {
		printf("delete failed\n");
	}
	display(list);

	status = find(list, "a0");
	if (status) {
		printf("a0 not find\n");
	} else {
		printf("a0 find \n");
	}

	status = find(list, "a1");
		if (status) {
			printf("a1 not find\n");
		} else {
			printf("a1 find \n");
		}

	destroy(list);

}

