bin/main: src/mainRational.cpp src/rational.cpp bin/rational.o
	g++ -o bin/main src/mainRational.cpp bin/rational.o

bin/rational.o: src/rational.cpp
	g++ -o bin/rational.o -c src/rational.cpp

exec:
	bin/main
