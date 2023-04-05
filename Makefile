all:
	g++ -Isrc/include -Lsrc/lib -o main main.cpp run.cpp core.cpp \
	drawBoard.cpp checkWin.cpp checkTie.cpp drawXO.cpp displayResImage.cpp modeGame.cpp vsComputer.cpp vsPlayer.cpp \
	-lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

