CC = gcc
CFLAGS = -Wall -Wextra -g
CFLAGS += -DDEBUG

all: testbst


testbst: trees/TestTrees.o trees/BST.o
	$(CC) $(CFLAGS) -o testbst trees/TestTrees.o trees/BST.o

trees/TestTrees.o: trees/TestTrees.c trees/BST.h
	$(CC) $(CFLAGS) -c trees/TestTrees.c -o trees/TestTrees.o

trees/BST.o: trees/BST.c trees/BST.h
	$(CC) $(CFLAGS) -c trees/BST.c -o trees/BST.o

clean:
	rm -f trees/*.o testbst
