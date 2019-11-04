all: linkedList.o arrayLibrary.o main.o
	gcc -o test_list linkedList.o arrayLibrary.o main.o

main.o: main.c linkedListHeader.h arrayLibraryHeader.h
	gcc -c main.c

linkedList.o: linkedList.c linkedListHeader.h
	gcc -c linkedList.c

arrayLibrary.o: arrayLibrary.c arrayLibraryHeader.h
	gcc -c arrayLibrary.c

run:
	./test_list

clean:
	rm *.o
	rm *~
