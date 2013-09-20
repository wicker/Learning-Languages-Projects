/* Jen Hanni [CS163] "prog2csairways.h" [Program #2] */

#include <iostream>
#include <cstring>
#include <cctype>
#include <iomanip>

using namespace std;

struct data {
};

class node
{
	public:
		node();
		node(char * newname);
		~node();
		node * next;
		compare(char * name);
		display(char * name);
	private:
		char * name;
		int ticket;
		char * seat;

};

class queue // queue
{
	public: 
		queue();
		~queue();
		int enqueue(const node&);
		int dequeue(node&);
		int peek(node&)
		int isEmpty();
		int isFull();
		int find(node * current, node * symtodrop);
		void get(char * nametoget);
	private:
		node * head;
		
};
