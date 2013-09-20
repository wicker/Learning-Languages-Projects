// Jenner Hanni  
// Symbl table assignment from 
// http://web.cecs.pdx.edu/~karlaf/CS163_Spring2011/Prog1.html

/* Needs deconstructors in nodes and sanitized inputs */

#include <iostream>
#include <cstring>
#include <cctype>
#include <iomanip>

using namespace std;

class node
{
	public:
		node();
		node(char * newname, char * newtype, char * newvalue);
		node(char * name);
		~node();
		node * next;
		int compare(node& source);
		int set(node& source);
		char* displayname();
		char* displaytype();
		char* displayvalue();
	private:
		char * name;
		char * type;
		char * value;
};

class symbolTable
{
	public: 
		symbolTable();
		~symbolTable();
		int add(char * name, char * type, char * value);
		int drop(char * name);
		int find(node * &current, node * symtodrop);
		int set(char * newname, char * newtype, char * newvalue); 
		void getAll();
		void get(char * nametoget);
	private:
		node * head;
};


