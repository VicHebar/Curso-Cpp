bin/main: src/mainOperaciones.cpp bin/operaciones.o
	g++ -o bin/main src/mainOperaciones.cpp bin/operaciones.o

bin/operaciones.o: src/operaciones.cpp
	g++ -o bin/operaciones.o -c src/operaciones.cpp

exec:
	bin/main
