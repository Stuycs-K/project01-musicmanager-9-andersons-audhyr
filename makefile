default: 
compile runme:   linkedlist.o main.o
	@gcc -o runme main.o linkedlist.o -lm
main.o: main.c linkedlist.h
	@gcc -c main.c
linkedlist.o: linkedlist.c
	@gcc -c linkedlist.c
run: runme
	@./runme
clean:
	@rm -rf runme *.gch *.o


