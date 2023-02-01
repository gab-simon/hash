flags = -std=c99 -Wall
program = myht

all: $(program)

$(program): myht.o hash.o bst.o
	gcc -o $(program) myht.o hash.o bst.o $(flags)

myht.o: myht.c
	gcc -c myht.c $(flags)

hash.o: hash.h hash.c
	gcc -c hash.c $(flags)

bst.o: bst.h bst.c
	gcc -c bst.c $(flags)

clean:
	rm -f *.o *.gch $(program)

purge:
	rm -f *.o *.gch $(program)
	clear