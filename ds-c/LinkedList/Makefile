LinkedListTest:LinkedList.o
	gcc -Wall -I. LinkedListTest.c LinkedList.o -o LinkedListTest 



LinkedList.o: LinkedList.h LinkedList.c
	gcc -Wall -I. -c LinkedList.c -o LinkedList.o

clean:
	-rm *.o
	-rm LinkedListTest
