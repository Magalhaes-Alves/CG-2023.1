
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

$(OBJ)/main.o:	$(SRC)/main.cpp 
	$(CC) $(CFLAGS) -c $(SRC)/main.cpp -o $(OBJ)/main.o

$(OBJ)/%.o:	$(CLASS)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Comandos para cada teste:
# circleTest - 
#g++ -Wall -Wextra -std=c++17 -o ./bin/circle.exe src/classes/Window.cpp src/test/circleTest.cpp -lSDL2

#ellipseTest	
#g++ -Wall -Wextra -std=c++17 -o ./bin/ellipse.exe src/classes/Window.cpp src/test/ellipseTest.cpp -lSDL2	

environment:
	sudo apt install libsdl2-dev
	mkdir $(OBJ)

clean:
	@rm $(BIN)/*
	@rm $(OBJ)/*

#compile:
#	g++ -o bin/main.exe src/main.cpp src/classes/Window.cpp pkg-config --cflags --libs sdl2
#clear:
#	rm bin/*
#xecute:
#	./bin/main.exe