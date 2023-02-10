CXX = g++
CXXFLAGS = -g -std=c++17 -Wall
OBJECTS = main.o board.o
FILES = main board

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf $(FILES) *.o