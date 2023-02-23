CXX = g++
CXXFLAGS = -g -std=c++17 -Wall
OBJECTS = main.o board.o udp-client.o udp-server.o game.o
FILES = main board udp-client udp-server game

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf $(FILES) $(OBJECTS)