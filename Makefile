all: compile run clean doc

compile:
	g++ -g -Wall -pedantic -std=c++17 src/*.cpp -o yantaeln -lstdc++fs;

run:
	./yantaeln	

clean:
	rm yantaeln
	
doc: 
	
