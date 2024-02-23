EXE=main
CC=g++
OBJS=main.o \
	vector.o

all: main

main: $(OBJS)

%.o: %.cpp
	$(CC) -c $< -o $@
clean:
	rm -rf *.o *.exe $(EXE)
