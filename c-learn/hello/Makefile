bin/hello: obj/hello.o #不能将obj/hello.o写为hello.o
	gcc obj/hello.o -o bin/hello

obj/hello.o: src/hello.c include/hello.h
	gcc -Iinclude -c src/hello.c -o obj/hello.o

.PHONY: clean
clean:
	-rm obj/*
	-rm bin/*

