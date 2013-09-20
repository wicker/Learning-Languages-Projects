// Jenner Hanni  
// Symbl table assignment from 
// http://web.cecs.pdx.edu/~karlaf/CS163_Spring2011/Prog1.html

#include "prog1symtable.h"

using namespace std;

int main()
{
	symbolTable *myTable = new symbolTable();
	// this dynamically creates a symbolTable called myTable;
	// the keyword new calls a constructor
	// the symbolTable is the name of that constructor
	// the constructor is a function so the parentheses are part of the name

	int choice = -1;

  cout 	<< "**********************************************" << endl
	<< "***********   SYMBOL    TABLE   ********* *****" << endl
	<< "**********************************************" << endl
	<< endl
	<< "The symbol table currently contains no symbols." << endl
	<< "Each symbol entry contains the symbol name, " << endl
	<< "value, and ID number. The list is sorted " << endl
	<< "by symbol name." << endl;

	while (choice != 0)
	{

  cout  << endl 
	<< "###########################################" << endl
	<< "###########################################" << endl
	<< "###########################################" << endl
	<< "#### Please enter a number:            ####" << endl
	<< "####                                   ####" << endl
	<< "#### 1. Add a new symbol.              ####" << endl
	<< "#### 2. Modify a symbol.               ####" << endl
	<< "#### 3. Drop a symbol.                 ####" << endl
	<< "#### 4. Retrieve an individual symbol. ####" << endl
	<< "#### 5. Display the entire table.      ####" << endl
 	<< "#### 6. To end the program and exit.   ####" << endl
	<< "###########################################" << endl
	<< "###########################################" << endl
	<< "###########################################" << endl;

	cin >> choice;

  	  switch (choice)
	  {
	  case 1:	// add a new symbol to a table ordered by name
		char newname[20];
		char newtype[20];
		char newvalue[20];

		cout << "###########################################" << endl
		     << "#### You chose " << choice << ": to add a new symbol. ####" << endl
		     << "#### What's the name of this symbol? ######" << endl
		     << "#### Name: ";
		cin  >> newname;
		cout << "#### What's the type of this symbol? ######" << endl
		     << "#### Type: ";
		cin  >> newtype;
		cout << "#### What's the value of this symbol? ####" << endl
		     << "#### Value: ";
		cin  >> newvalue;

		int temp;
		temp = myTable->add(newname, newtype, newvalue);

		if (temp == 0)
		{ 
		cout << endl << "****************************************" 
		     << endl << "The symbol '" << newname 
		     << "' was successfully added!" << endl; 
		}
		else if (temp == 2)
		{
		cout << endl << "The symbol '" << newname 
		     << "' already exists." << endl;
		}
		else 
		{ 
		cout << "You broke the system! Remember: fail better." << endl; 
		}
		
		break;

	  case 2:	// modify an existing symbol entry in the table

		cout << "You chose " << choice << ": to modify an existing symbol." << endl
		     << endl << "What's the name of this symbol? ";
		cin  >> newname;
		cout << "What's the new type? ";
		cin  >> newtype;
		cout << "What's the new value? ";
		cin  >> newvalue;

		temp = myTable->set(newname, newtype, newvalue);
	
		if (temp == 0)
		{ 
		cout << endl << "****************************************" 
		     << endl << "The symbol '" << newname 
		     << "' was successfully found and modified!" << endl; 
		}
		else if (temp == 1)
		{
		cout << endl << "The list is empty!" << endl;
		}
		else if (temp == 2)
		{
		cout << endl << "The symbol wasn't found. Please add it." << endl;
		}
		else if (temp == 3)
		{
		cout << endl << "There was an error. Please try again." << endl;
		}
		else 
		{ 
		cout << "The symbol wasn't found." << endl; 
		}
		
		break;
	
	  case 3:	// drop a symbol from the table
		char nametodrop[20];

		cout << "You chose " << choice 
		     << ": to remove an existing symbol." << endl
		     << "What's the name of this symbol? ";
		cin  >> nametodrop;
		
		if (myTable->drop(nametodrop) == 0)
		{
		cout << "The symbol '" << nametodrop << "' was successfully removed." << endl;
		}
		else 
		{
		cout << "The symbol '" << nametodrop << "' could not be removed." << endl
		     << "Are you sure you entered the name correctly?" << endl;
		}
		break;

          case 4:	// displays the specified symbol's name, type, and value
		char nametodisplay[20];
	        cout << "You chose " << choice 
		     << ": display the entry information for a symbol."  << endl
		     << "What's the name of this symbol? ";
		cin  >> nametodisplay;

		myTable->get(nametodisplay);

		break;

	  case 5:
	        cout << "You chose " << choice 
		     << ": to display the entire symbol table."<< endl;
		myTable->getAll();
		break;

	  case 6:
		cout << "You chose " << choice << ": to exit. The program will "
 		     << "now end. Thanks for playing! " << endl;
		return 0;
 	  }
	}

	cout << "Please try another selection. " << endl;


	return 0;

	delete myTable;
}
