#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main(void) {
	LinkedList* list = create();

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
