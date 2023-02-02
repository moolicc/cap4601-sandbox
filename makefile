CXX = g++
CXXFLAGS = -g -std=c++17 -Wall
OBJECTS = main.o cell.o board.o
FILES = main cell board

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf *.dSYM
	$(RM) *.o *.gc* $(FILES)