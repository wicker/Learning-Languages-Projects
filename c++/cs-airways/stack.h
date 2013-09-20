/* Jen Hanni [CS163] "prog2csairways.h" [Program #2] */

#include <iostream>
#include <cstring>
#include <cctype>
#include <iomanip>

using namespace std;

struct data {
		char * name;
		int ticket;
		char * seat;
};

class node
{
	public:
		node();
		node(char * newname, char * newticket, char * newseat);
		node(char * name);
		~node();
		node * next;
		int compare(node& source);
		int set(node& source);
		char displayname(node& source);
	private:
		data * passenger;

};

class ticketQueue // queue
{
	public: 
		ticketQueue();
		~ticketQueue();
		int enqueue(const node&);
		int dequeue(node&);
		int peek(node&)
		int isEmpty();
		int isFull();
		int find(node * current, node * symtodrop);
			// if not found, either never arrived or deplaned
		void get(char * nametoget);
	private:
		node * head;
		
};

class boardedStack // stack
{
	public:
		boardedStack();
		~boardedStack();
		int push(const node&);
		int pop(node&);
		int peek(nod&);
		int isEmpty();
		int isFull();
	private:
		node * head;
};
