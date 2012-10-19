#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define MAX_SIZE 50

typedef char ElemType;

typedef struct {
	ElemType data[MAX_SIZE];
	int length;
} SqList;

/* 建立顺序表 */
void CreateList(SqList *L, ElemType a[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		L->data[i] = a[i];
	}

	L->length = n;
}

SqList* InitList(void) {
	printf("Init List\n");
	SqList* L = (SqList *) malloc(sizeof(SqList));
	L->length = 0;
	return L;
}

void DestroyList(SqList *L) {
	free(L);
}

/*为空，返回1，否则返回0*/
int EmptyList(SqList *L) {
	return 0 == L->length;
}

int length(SqList *L) {
	return L->length;
}

void display(SqList *L) {
	int i;
	//	printf("list length=%d\n", L->length);
	printf("display SqList: ");
	for (i = 0; i < L->length; i++) {
		printf("%c ", L->data[i]);
	}

	printf("\n");
}

int getElem(SqList *L, int i, ElemType* e) {
	if (i < 0 || i >= L->length) {
		return 0;
	}

	int j;
	*e = L->data[i];
	return 1;
}

//返回元素在顺序表中的位置，0~.., 如果没有返回-1
int locateElem(SqList *L, ElemType e) {
	int i;
	for (i = 0; i < L->length; i++) {
		if (L->data[i] == e) {
			return i;
		}
	}

	return -1;
}

int insert(SqList *L, int i, ElemType e) {
	if (i < 0 || i > L->length) {
		return 0;
	}
	// 将data[i]及以后的元素后移
	int j;
	for (j = L->length; j > i; j--) {
		L->data[j] = L->data[j - 1];
	}
	L->data[i] = e;
	L->length++;
	return 1;
}

int deleteElem(SqList *L, int i, ElemType *e) {
	if (i < 0 || i >= L->length) {
		return 0;
	}

	*e = L->data[i];

	//把data[i]后的元素往前移
	int j;
	for(j=i; j<L->length-1; j++){
		L->data[j] = L->data[j+1];
	}
	L->length--;
	return 1;
}

int main(int argc, char* argv[]) {
	printf("SqList test==>\n");

	int op_ret;
	SqList* L;
	L = InitList();
	//	printf("length=%d\n", L->length);
	op_ret = EmptyList(L);
	//	printf("is empty %d\n", op_ret);
	ElemType a[] = { 'a', 'b', 'c' };
	CreateList(L, a, 3);
	display(L);

	op_ret = insert(L, 0, 'd');
	printf("insert ret %d\n", op_ret);
	display(L);

	op_ret = insert(L, 4, 'e');
	printf("insert ret %d\n", op_ret);
	display(L);

	op_ret = insert(L, 3, 'e');
	printf("insert ret %d\n", op_ret);
	display(L);

	ElemType e;
	int pos;
	pos = 2;
	op_ret = getElem(L, pos, &e);
	printf("getElem %d, ret %d, and element is %c\n", pos, op_ret, e);
	pos = 0;
	op_ret = getElem(L, pos, &e);
	printf("getElem %d, ret %d, and element is %c\n", pos, op_ret, e);
	pos = 5;
	op_ret = getElem(L, pos, &e);
	printf("getElem %d, ret %d, and element is %c\n", pos, op_ret, e);
	pos = 6;
	op_ret = getElem(L, pos, &e);
	printf("getElem %d, ret %d, and element is %c\n", pos, op_ret, e);

	e = 'd';
	op_ret = locateElem(L, e);
	printf("locate elem %c, the position is %d\n", e, op_ret);
	e = 'e';
	op_ret = locateElem(L, e);
	printf("locate elem %c, the position is %d\n", e, op_ret);
	e = 'x';
	op_ret = locateElem(L, e);
	printf("locate elem %c, the position is %d\n", e, op_ret);

	printf("\n\n\n");

	display(L);
	pos = 0;
	op_ret = deleteElem(L, pos, &e);
	printf("delete elem %d, element is %c, ret is %d\n", pos, e, op_ret);
	display(L);
	pos = 2;
	op_ret = deleteElem(L, pos, &e);
	printf("delete elem %d, element is %c, ret is %d\n", pos, e, op_ret);
	display(L);
	pos = 6;
	op_ret = deleteElem(L, pos, &e);
	printf("delete elem %d, element is %c, ret is %d\n", pos, e, op_ret);
	display(L);
	pos = 3;
	op_ret = deleteElem(L, pos, &e);
	printf("delete elem %d, element is %c, ret is %d\n", pos, e, op_ret);
	display(L);

	DestroyList(L);

}

