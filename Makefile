EXE=main
CC=g++
OBJS=main.o vector.o
CXXFLAGS=-Wall -pedantic

all: main

main: $(OBJS)

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@
clean:
	rm -rf *.o *.exe $(EXE)
