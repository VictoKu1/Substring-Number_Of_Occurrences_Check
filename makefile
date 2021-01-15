all : frequency

frequency : frequency.o
	gcc -g -Wall frequency.o -o frequency

frequency.o : frequency.c
	gcc -g -Wall  -c frequency.c -o frequency.o

.PHONY : all clean

clean :
	rm frequency *.o 




