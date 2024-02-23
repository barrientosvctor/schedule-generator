EXE=output
COMPILER=g++
OBJS=main.o \
    vector.o

all: main

main: $(OBJS)
	$(COMPILER) $? -o $(EXE) && ./$(EXE)

main.o: main.cpp

vector.o: vector.cpp

clean:
	rm -rf *.o *.exe $(EXE)
