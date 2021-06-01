CXXFLAGS: -std=c++11 -Wall
all: movies.o utility.o main.cpp tests.o
	g++ $(CXXFLAGS) main.cpp movies.o utility.o -o runMovies
	g++ $(CXXFLAGS) tests.o movies.o -o tests
runMovies: movies.o utility.o main.cpp
	g++ $(CXXFLAGS) main.cpp movies.o utility.o -o runMovies
tests: tests.o movies.o
	g++ $(CXXFLAGS) tests.o movies.o -o tests
movies.o: movies.cpp movies.h
	g++ $(CXXFLAGS) -c movies.cpp
utility.o: utility.cpp utility.h
	g++ $(CXXFLAGS) -c utility.cpp
test.o: test.cpp tests.h
	g++ $(CXXFLAGS) -c tests.cpp
clean:
	rm *.o -f runMovies tests