/*
 * LinkedList.h
 *
 *  Created on: Oct 18, 2012
 *      Author: xrleng
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

typedef char ElemType;
typedef int Status;

typedef struct LNode{
	ElemType* data;
	struct LNode* next;
}LinkedList;

int create(LinkedList* list);

void destroy(LinkedList* list);

void display(LinkedList* list);

int insert(LinkedList* list, ElemType* e);

int delete(LinkedList* list, ElemType* e);

int find(LinkedList* list, ElemType* e);


















#endif /* LINKEDLIST_H_ */
