/* Three steps:
   Enter all ticketed passengers for this flight.
   Create a boarding stack from this queue.
   Display the list of passengers which may board the airplane. */

/* Jen Hanni [CS163] "prog2application.cpp" [Program #2] */

#include "prog1symtable.h"

using namespace std;

int main()
{
	ticketQueue *myQueue = new ticketQueue();
	boardedStack *myStack = new boardedStack();

	int choice = -1;

  cout 	<< "**************************************************" << endl
	<< "**************   CS AIRWAYS MENU   ***************" << endl
	<< "**************************************************" << endl
	<< endl
	<< "Welcome to the interactive menu for Flight CS484. " << endl
 	<< "Please select (1) to enter a set of ticketed " << endl
	<< "traveler names; ticket numbers and seat assignments " << endl
	<< "will be automagically generated. Then select (2) to " << endl
	<< "generate a list of travelers eligible to board, in " << endl
	<< "boarding order. CS Airways is proud to be a 'first " << endl
	<< "ticketed? you're first-to-board!' airline. " << endl;

	while (choice != 0)
	{

  cout  << endl 
	<< "Please enter the number of your choice: " << endl
	<< endl
	<< "1. Check in a traveler. " << endl
	<< "2. Print the final boarding list. " << endl
 	<< "3. To end the program and exit. " << endl;

	cin >> choice;

  	  switch (choice)
	  {
	  case 1:	// add a new symbol to the queue
			// ask if the user wants to add another symbol to the queue
		char newname[20];
		char newticket[7];
		char newseat[3];
		int success;

		cout << "You chose " << choice << ": to add a new traveler." << endl
		     << "This airplane has nine rows with five rows across; " << endl
		     << "therefore, you may enter up to 45 travelers. " << endl
		     << "You have entered " << count << " travelers. " << endl
		     << "What's the name of the next traveler? ";
		cin  >> newname;

		int temp;
		temp = myQueue->add(newname, newticket, newseat);
		// return 0 if the passenger was successfully created and added to the queue

		if (temp == 0)
		{
			cout << endl << "****************************************" 
		   	     << endl << "The traveler has been entered; "
			     << endl << "You may send them to their gate!" << endl; 
		}
		else 
		{ 
			cout << "There was a problem with this entry. "
			     << endl << "Try another selection! " << endl; 
		}
		
		break;

//	  case 2:	// dequeues a node, prints details, puts it into the boarding stack
			// does this for the whole list so that the list comes out in boarding order
//		cout << "You chose " << choice << ": to view the status of a traveler." << endl
//		     << endl << "What's the name of this traveler? ";
//		cin  >> newname;
//
//			// find this traveler
//				// if 0 (exists)
//					// display the information
//				// if 1 (not found)
//					// return failure
//
//		break;
//	
	  case 3:
		cout << "You chose " << choice << ": to exit. The program will "
 		     << "now end. Thanks for playing! " << endl;
		return 0;
 	  }
	}

	cout << "Please try another selection. " << endl;


	return 0;

}
