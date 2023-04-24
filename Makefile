all:
	g++ -Isrc/include -Lsrc/lib -o main main.cpp run.cpp core.cpp \
	draw.cpp drawXO.cpp sideBar.cpp score.cpp \
	displayResImage.cpp modeGame.cpp checkWin.cpp checkTie.cpp \
	vsComputer.cpp vsPlayer.cpp \
	-lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

