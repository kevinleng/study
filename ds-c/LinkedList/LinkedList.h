/*
 * LinkedList.h
 *
 *  Created on: Oct 18, 2012
 *      Author: xrleng
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#define OK 1
#define FAIL 0

typedef char ElemType;
typedef int Status;

typedef struct {
	ElemType* data;
	struct LinkedList* next;
}LinkedList;

LinkedList* create();

void destroy(LinkedList* list);

void display(LinkedList* list);

void insert(LinkedList* list, int pos, ElemType* e);

ElemType* delete(LinkedList* list, int pos);

Status find(LinkedList* list, ElemType* e);


















#endif /* LINKEDLIST_H_ */
