.PHONY: build_lib
build_lib: bin/libds_tree.a

bin/libds_tree.a: obj/ds_tree.o
	ar -r bin/libds_tree.a obj/ds_tree.o

obj/ds_tree.o: src/ds_tree.o include/ds_tree.h
	gcc -fpic -Iinclude -c src/ds_tree.c -o obj/ds_tree.o
	
.PHONY:test
test: bin/test
bin/test: bin/libds_tree.a obj/test_ds_tree_main.o
	gcc obj/test_ds_tree_main.o -Lbin -lds_tree -o bin/test

obj/test_ds_tree_main.o:src/test_ds_tree_main.c include/ds_tree.h
	gcc -Iinclude -c src/test_ds_tree_main.c -o obj/test_ds_tree_main.o

.PHONY: clean
clean:
	-rm obj/*.o
	-rm bin/*