
#Variaveis para ajudar na compilação
SRC = ./src
CLASS = ./src/classes
OBJ = ./src/obj
BIN = ./bin
CC = g++
DEP = $(OBJ)/main.o $(OBJ)/Window.o
CFLAGS = -Wall -Wextra

execute:	$(BIN)/main.exe
	./bin/main.exe
	

$(BIN)/main.exe:	$(DEP)
	$(CC) $(CFLAGS) -o $(BIN)/main.exe $(OBJ)/*.o  -lSDL2
	rm $(OBJ)/*

$(OBJ)/main.o:	$(SRC)/main.cpp 
	$(CC) $(CFLAGS) -c $(SRC)/main.cpp -o $(OBJ)/main.o

$(OBJ)/%.o:	$(CLASS)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

#$(OBJ)/Window.o:	$(CLASS)/Window.cpp
#	$(CC) -c $(CLASS)/Window.cpp -o $(OBJ)/Window.o 

	
clean:
	@rm ./bin/*
	@rm ./obj/*

#compile:
#	g++ -o bin/main.exe src/main.cpp src/classes/Window.cpp pkg-config --cflags --libs sdl2
#clear:
#	rm bin/*
#xecute:
#	./bin/main.exe