default: compile
compile runme:   linkedlist.o main.o library.o
	@gcc -o runme main.o linkedlist.o library.o -lm
main.o: main.c linkedlist.h library.h
	@gcc -c main.c
linkedlist.o: linkedlist.c
	@gcc -c linkedlist.c
library.o: library.c
	@gcc -c library.c
run: runme
	@./runme
clean:
	@rm -rf runme *.gch *.o


