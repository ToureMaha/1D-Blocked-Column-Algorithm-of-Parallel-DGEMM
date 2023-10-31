CC = g++
CFLAGS = -std=c++11 -g -Wall
DEPS = utility.h filer.h heapsort.h timer.h utility.h columnsort.h

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

filer: main.o filer.o heapsort.o timer.o utility.o columnsort.o
	$(CC) -o main main.o filer.o heapsort.o timer.o utility.o columnsort.o

clean:
	rm -f main.o filer.o heapsort.o timer.o utility.o columnsort.o