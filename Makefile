all: func.o main.o
	gcc main.o func.o


func.o: func.c
	gcc -c func.c
main.o: main.c
	gcc -c main.c
clean:
	rm *.o
install:
	cp a.out /usr/bin
