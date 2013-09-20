prog1: prog1application.o prog1symtable.o
	g++ -g prog1application.o prog1symtable.o -o prog1

prog1symtable.o: prog1application.cpp
	g++ -c prog1application.cpp

prog1symtable.o: prog1symtable.cpp
	g++ -c prog1symtable.cpp

clean:
	rm -rf *o prog1 prog1application.o prog1symtable.o 

