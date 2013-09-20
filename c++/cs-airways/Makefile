prog2: application.o stack.o queue.o 
	g++ -g application.o stack.o queue.o -o prog2

application.o: application.cpp
	g++ -c application.cpp

stack.o: stack.cpp
	g++ -c stack.cpp

queue.o: queue.cpp
	g++ -c queue.cpp

clean:
	rm -rf *o prog1
