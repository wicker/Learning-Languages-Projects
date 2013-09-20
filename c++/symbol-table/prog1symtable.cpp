/* Jen Hanni [CS163] "prog1symtable.cpp" [Program #1] */

#include "prog1symtable.h"

/* Node */

node::node() 
{
	node * next = NULL;
	char * name;
	char * type;
	char * value;
}

node::node(char * newname, char * newtype, char * newvalue) 
{
	node * next = NULL;
	if(newname) {
		int namelen = strlen(newname) + 1;
		name = new char[namelen];
		strncpy(name, newname, namelen);
	}
	if(newtype) {
		int typelen = strlen(newtype) + 1;
		type = new char[typelen];
		strncpy(type, newtype, typelen);
	}
	if(newvalue) {
		int valuelen = strlen(newvalue) + 1;
		value = new char[valuelen];
		strncpy(value, newvalue, valuelen);
	}
}

node::node(char * newname)
{
	node * next = NULL;
	if(newname) {
		int namelen;
		namelen = strlen(newname) + 1;
		name = new char[namelen];
		strncpy(name, newname, namelen);
	}
	char * type;
	char * value;
}

node::~node() {
	delete next; 
	delete[] name;
	delete[] type;
	delete[] value;
}

int node::compare(node& source) 
{
	int val;
	val = strcmp(name, source.name);
	return val;
}

int node::set(node& source)
{
	if(source.name) {
		int namelen = strlen(source.name) + 1;
		name = NULL;
		name = new char[namelen];
		strncpy(name, source.name, namelen);
	}
	if(source.type) {
		int typelen = strlen(source.type) + 1;
		type = NULL;
		type = new char[typelen];
		strncpy(type, source.type, typelen);
	}
	if(source.value) {
		int valuelen = strlen(source.value) + 1;
		value = NULL;
		value = new char[valuelen];
		strncpy(value, source.value, valuelen);
	}
	return 0;
}

/****************/
/* Symbol Table */
/****************/

/* symbol table :: constructor */

symbolTable::symbolTable()
{
	node * head = NULL;
}

symbolTable::~symbolTable() {
	delete head;
}

/* symbol table :: creates a new symbol, adds it to the list */

// strcmp(str1,str2) returns 0 when the strings are equal
// strcmp(str1,str2) returns a negative integer when s1 < s2
// strcmp(str1,str2) returns a positive integer when s1 > s2

int symbolTable::add(char * newname, char * newtype, char * newvalue) 
{
	node * symtoadd = new node(newname, newtype, newvalue);
	node * current = head;

	while (current)
	{
		if (current->compare(*symtoadd) == 0)
		{
			return 2;
		}
		else if (current->compare(*symtoadd) > 0)
		{
			symtoadd->next = current;
			head = symtoadd;
			return 0;
		}
		if (current->next)
		{
			if (current->next->compare(*symtoadd) == 0)
			{
				return 0;
			}
			else if (current->next->compare(*symtoadd) > 0)
			{
			
	symtoadd->next = current->next;
				current->next = symtoadd;
				return 0;
			}
		current = current->next;
		}
		else
		{
			symtoadd->next = current->next;
			current->next = symtoadd;
		}
	}
	// if an empty list, make the new symbol the head
	head = symtoadd; 
	return 0;
}

int symbolTable::drop(char * nametodrop)
{
	node * symtodrop = new node(nametodrop);
	node * current = head;

	if (!current) 
	{ 
		return 1; 
	}
	else if (current->compare(*symtodrop) == 0)
	{
		head = head->next;
		delete current;
		return 0;
	}
	else if (find(current->next, symtodrop) == 0)
	{
		node * temp = current->next;
		current->next = current->next->next;
		delete temp;
		return 0;
	}
	else if (find(current->next, symtodrop) != 0)
	{
		return 1;
	}
}

void symbolTable::getAll()
{
	node * symtoget = head;

	if (!symtoget)
	{ 
	cout << "This is an empty list. " << endl;
	}
	else while (symtoget->next)
	{
	cout << "Name: " << symtoget->displayname() << endl;
	cout << "Type: " << symtoget->displaytype() << endl;
	cout << "Value: " << symtoget->displayvalue() << endl;
	symtoget = symtoget->next;
	}

	cout << "Name: " << symtoget->displayname() << endl;
	cout << "Type: " << symtoget->displaytype() << endl;
	cout << "Value: " << symtoget->displayvalue() << endl;
}	

void symbolTable::get(char * nametoget)
{
	node * symtoget = new node(nametoget);
	node * current = head;

	if (!current)
	{
	cout << "This is an empty list. " << endl;
	}
	while (find(current, symtoget) < 0)
	{
		current = current->next;
	}
	if(find(current, symtoget) == 0)
	{
	cout << "Name: " << current->displayname() << endl;
	cout << "Type: " << current->displaytype() << endl;
	cout << "Value: " << current->displayvalue() << endl;
	}
	else 
	{
	cout << "The symbol wasn't found." << endl;
	}
}

char* node::displayname()
{
	return name;
}

char* node::displaytype()
{
	return type;
}

char* node::displayvalue()
{
	return value;
}

int symbolTable::set(char * newname, char * newtype, char * newvalue) 
{
	node * symtoset = new node(newname, newtype, newvalue);
	node * current = head;

	if (!current) 
	{ 
		return 1; // "list is empty"
	}

	while (find(current, symtoset) != 0 && current)
	{
		current = current->next;
	}

	if (!current)
	{
		return 2; // "symbol name not found"
	}

	else if (find(current, symtoset) == 0)
	{
		if (current->set(*symtoset) == 0)
		{
			return 0;  // "symbol successfully changed"
		}
		else
		{
			return 3;  // "there was a failure"
		}
	}
	else if (find(current, symtoset) == 1)
	{
		return 3;  // here as well
	}
}

int symbolTable::find(node * & current, node * symtodrop) 
{
	int status = 1;
	if (current)
	{
		status = current->compare(*symtodrop);
		if (status == 1) 
		{
		return find(current->next, symtodrop);
		}
	}
	return status; 
}
