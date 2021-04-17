g=gcc
c=-Wall	-std=c99
fleschIndex:	fleschIndex.o	main.o
	$(g)	$(c)	fleschIndex.o	main.o	-o	fleschIndex	-lm
fleschIndex.o:	fleschIndex.c	fleschIndex.h
	$(g)	$(c)	-c	fleschIndex.c	-lm
main.o:	main.c	fleschIndex.h
	$(g)	$(c)	-c	main.c	-lm
clean:
	rm	*.o	fleschIndex