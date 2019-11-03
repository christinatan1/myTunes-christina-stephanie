all: linkedList.o linkedListMain.o
	gcc -o test_list linkedList.o linkedListMain.o

linkedListMain.o: linkedListMain.c linkedListHeader.h
	gcc -c linkedListMain.c

linkedList.o: linkedList.c linkedListHeader.h
	gcc -c linkedList.c

run:
	./test_list

clean:
	rm *.o
	rm *~
