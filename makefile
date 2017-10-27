all: devrandom.c
	gcc devrandom.c

run: all
	./a.out

clean:
	rm *.o
	rm *~
	rm a.out
