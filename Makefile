# CC=g++
# CFLAGS=-ISrc/include
# LDFLAGS=-LSrc/lib
# LIBS=-lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
# SRC=Main.cpp Core.cpp Run.cpp Draw.cpp SideBar.cpp Result.cpp Mode.cpp Play.cpp Check.cpp Computer.cpp

# all: TicTacToe.exe

# TicTacToe.exe: $(SRC)
# 	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

# .PHONY: clean
# clean:
# 	rm -f TicTacToe.exe

TicTacToe: main.cpp
	g++ -ISrc/include -LSrc/lib -o TicTacToe main.cpp Core.cpp \
	Run.cpp Draw.cpp SideBar.cpp Result.cpp \
	Mode.cpp Play.cpp Check.cpp Computer.cpp \
	-lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer