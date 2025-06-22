all : frequency

frequency : frequency.o
	gcc -g -Wall frequency.o -o frequency

frequency.o : frequency.c frequency.h
	gcc -g -Wall -c frequency.c

.PHONY : clean all
clean :
	rm -f frequency *.o *.gch