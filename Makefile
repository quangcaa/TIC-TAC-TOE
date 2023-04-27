all:
	g++ -Isrc/include -Lsrc/lib -o main main.cpp core.cpp \
	run.cpp draw.cpp sideBar.cpp display.cpp \
	mode.cpp play.cpp gameOver.cpp \
	-lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

