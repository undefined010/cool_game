SRC = src/*.cpp
OUT = out/game


all:
	g++ -std=c++17 -Wall -Wextra $(SRC) -I ./lib/sfml/include -L ./lib/sfml/lib  -lsfml-graphics -lsfml-window -lsfml-system -o $(OUT)