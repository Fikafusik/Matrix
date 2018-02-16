
obj = main.o matrix.o square_matrix.o
exe = app.out

all: $(obj)
	g++ $(obj) -o $(exe)

main.o: main.cpp src/matrix.hpp src/square_matrix.hpp
	g++ -c main.cpp

matrix.o: src/matrix.cpp src/matrix.hpp
	g++ -c src/matrix.cpp

square_matrix.o: src/square_matrix.cpp src/square_matrix.hpp src/matrix.hpp
	g++ -c src/square_matrix.cpp

clean:
	rm $(obj) $(exe)