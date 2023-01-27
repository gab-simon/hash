flags = -std=c99 -Wall
program = myht

all: $(program)

$(program): main.o hash.o
	gcc -o $(program) main.o hash.o $(flags)

main.o: main.c
	gcc -c main.c $(flags)

hash.o: hash.h hash.c
	gcc -c hash.c $(flags)

clean:
	rm -f *.o *.gch $(program)

purge:
	rm -f *.o *.gch $(program)
	clear