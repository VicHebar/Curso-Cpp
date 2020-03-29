bin/ComplexProgram: src/mainComplex.cpp src/Complex.o
	g++ -o bin/ComplexProgram src/mainComplex.cpp src/Complex.o

src/Complex.o: src/Complex.cpp
	g++ -o src/Complex.o -c src/Complex.cpp

clean:
	rm -f src/Complex.o

exec:
	bin/ComplexProgram
