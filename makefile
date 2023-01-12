CXX = g++
CXXFLAGS = -g -std=c++11 -Wall

main: main.o
	$(CXX) $(CXXFLAGS) -o $@ $^


clean:
	rm -rf *.dSYM
	$(RM) *.o *.gc* main