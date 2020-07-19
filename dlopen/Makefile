all: james
	g++ main.cpp Hello.cpp HelloWrapper.cpp -o main -ldl
james: James.cpp
	g++ -fpic -c James.cpp
	g++ -shared -o libJames.so James.o
clean:
	rm *.o *.so main
