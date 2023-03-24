all:
	g++ -Isrc/include -Lsrc/lib -o main main.cpp icon.cpp checkWin.cpp checkTie.cpp drawXO.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
