EXE=output
COMPILER=g++

main: main.cpp
	$(COMPILER) $? -o $(EXE) && ./$(EXE)
