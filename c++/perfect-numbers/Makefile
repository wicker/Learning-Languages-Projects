prog1: perfectnumapp.o perfectnumgame.o
	g++ -g perfectnumapp.o perfectnumgame.o -o perfectnum

prog1symtable.o: perfectnumapp.cpp
	g++ -c perfectnumapp.cpp

prog1symtable.o: perfectnumgame.cpp
	g++ -c perfectnumgame.cpp

clean:
	rm -rf *o perfectnum perfectnumapp.o perfectnumgame.o

