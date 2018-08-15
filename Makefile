LIBS=-lsfml-system -lsfml-window -lsfml-graphics
SOURCES=src/*.cpp
OUTPUT=gamepadtest

all:
	g++ -std=c++11 $(SOURCES) $(LIBS) -o $(OUTPUT)

clean:
	rm $(OUTPUT)