EXE=output
COMPILER=g++
FILES_TO_COMPILE=main.cpp \
		vector.cpp \
		file.cpp

main: $(FILES_TO_COMPILE)
	$(COMPILER) $? -o $(EXE) && ./$(EXE)
