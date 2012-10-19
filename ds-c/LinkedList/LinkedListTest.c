#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main(void) {
	LinkedList* list = create();

	display(list);

	insert(list, "a0");
	insert(list, "a1");
	insert(list, "a2");
	insert(list, "a3");
	
	display(list);

    int op = delete(list, "a1");
	printf("delete ret %d\n", op);
	display(list);

    ElemType* e ;
    int findRet ;
    *e = "a1";
	findRet = find(list, e);
	printf("find %s ret %d\n",, findRet);
	
	*e = "a0";
	findRet = find(list, e);
	printf("find %s ret %d\n",, findRet);
	
	*e = "a3";
	findRet = find(list, e);
	printf("find %s ret %d\n",, findRet);
	
	*e = "ax";
	findRet = find(list, e);
	printf("find %s ret %d\n",, findRet);
	

	destroy(list);
	return EXIT_SUCCESS;
}
