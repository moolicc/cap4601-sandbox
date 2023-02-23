CXX = g++
CXXFLAGS = -g -std=c++17 -Wall
OBJECTS = main.o board.o udp-client.o udp-server.o
FILES = main board udp-client udp-server

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf $(FILES) *.o