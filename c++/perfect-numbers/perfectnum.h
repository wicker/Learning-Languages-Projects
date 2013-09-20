// Jenner Hanni
// Header 

#include <iostream>
#include <cstring>
#include <cctype>
#include <iomanip>

using namespace std;

class player
{
	public:
		player();
		~player();
	private:
		char * name;
		int points;
};

class number
{
	public: 
		number();
		~number();
		char isPAD();
		determineDivisors();
		char * displayType();
		char * displayValue();
		char * displayDivisors();
	private:
		int value;
		int divs[50];
		char type;
};

class perfectNumGame
{
	public: 
		perfectNumGame();
		~perfectNuMGame();
		setPlayers(int num);
		getPlayerTurn(int player);
		displayScore();
	private:
		int numPlayers;
};


