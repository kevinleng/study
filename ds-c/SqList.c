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

void InitList(SqList *&L) {
	printf("Init List\n");
	L = (SqList *)malloc(sizeof(SqList));
	L->length = 0;
}

void DestroyList(SqList *&L) {
	free(L);
}

/*为空，返回1，否则返回0*/
int EmptyList(SqList *L) {
	return L->length==0;
}

int length(SqList *L) {

}

void display(SqList *&L) {
	int i;
	printf("list length=%d\n", L->length);
	printf("display SqList: ");
	for(i=0;i<L->length;i++) {
		printf("%c ", L->data[i]);
	}

	printf("\n");
}

int getElem(SqList *L, int i, ElemType e) {

}

int locateElem(SqList *L, ElemType e) {

}

int insert(SqList *L, int i, ElemType e) {

}

int deleteElem(SqList *L, int i, ElemType e) {

}

int main(int argc, char* argv[]) {
	printf("SqList test==>\n");

	//	SqList L;
	//	ElemType a[] = {'a', 'c', 'd', '1', '9'};
	//	CreateList(&L, a, 5);
	//	display(&L);

	SqList *L;
	InitList(L);
	printf("L add=%p\n", L);
	display(L);

	printf("is empty %d\n", EmptyList(L));

	DestroyList(L);

}

