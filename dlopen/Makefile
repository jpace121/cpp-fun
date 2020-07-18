all: james
	g++ -L$(shell pwd)/ -Wl,-rpath $(shell pwd) main.cpp Hello.cpp -o main -ldl
james: James.cpp
	g++ -fpic -c James.cpp
	g++ -shared -o libJames.so James.o
clean:
	rm *.o *.so main
