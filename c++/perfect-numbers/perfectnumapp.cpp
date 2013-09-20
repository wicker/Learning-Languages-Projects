// Jenner Hanni
// c++
// Perfect Number Guessing Game

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cctype>
#include <iomanip>
#include <ctime>

using namespace std;

int main()
{
  //perfectNumberGame * myGame = new perfectNumberGame();
  // this dynamically creates a new object called myGame;
  // the keyword new calls a constructor
  // the symbolTable is the name of that constructor
  // the constructor is a function so the parentheses are part of the name

  int players = -1;

  int total1 = 0; 
  int total2 = 0;
  int total3 = 0;
  int total4 = 0;
  int guess = 0;
  int pad = 0;
  int divs[50];
  int totals[4];
  int num;
  int sum;
  bool validGuess = false;
  int player = 0;

  cout  
  << "**********************************************" << endl
  << "******** PERFECT NUMBER GUESSING GAME ********" << endl
  << "**********************************************" << endl
  << endl
  << "28 is a perfect number because all its proper " << endl
  << "divisors (1 + 2 + 4 + 7 + 14 = 28) sum to 28. " << endl
  << "Any number whose proper divisors sum to less " << endl
  <<  "than itself is said to be deficient; any that " << endl
  << "sums to more than itself is said to be abundant. " << endl
  << "In this game, up to four players will take turns " << endl
  << "guessing whether a given number is proper, deficient, " << endl
  << "or abundant. A correct answer gets 1 point. " << endl << endl

  << "Guess '1' for proper, '2' for abundant, and '3' for deficient." << endl << endl 
  << "The first player to ten points wins." << endl;

  cout  << endl << "How many players?" << endl;

  cin >> players;

  if (players > 4 || players < 1) {
    cout << "That's not a number between 1 and 4. Please try again." << endl;
  }
  cout << endl;

  srand(time(0));
  num = rand() % 50 + 1;

  cout << "Okay, player " << player + 1 << ". Your number is: " << num << "." << endl;
  cout << "Is the number (1) perfect, (2) abundant, or (3) deficient?" << endl;

  //divs = findProperDivisors(num);

  int j = 0;
  for (int i = 1; i < num; i++) {
    if (num % i) {
     divs[j] = i;
     j++;
    }
  }

  for (int i = 0; i < j - 1; i++) {
    sum += divs[i];
  }

  if (sum == num) 
    pad = 1;
  else if (sum > num) 
    pad = 2;
  else if (sum < num)
    pad = 3;

  //pad = isPAD(num, divs);

  do {
    cout << "Make a guess: ";
    cin >> guess;
    if (guess < 1 || guess > 3) 
      cout << "Guess 1 for perfect, 2 for abundant, or 3 for deficient." << endl;
    else 
      validGuess = true; 
  } while (validGuess == false);

  if (pad == guess) {
    totals[player]++;
    cout << "You're correct! Player " << player + 1 << " now has " << totals[player] << " points!" << endl;
  }
  else
    cout << "You're wrong! " << num << " has " << j << 
	    " divisors which add up to " << sum << ". It's " << pad << "!" << endl;

  if (player < 3) player++;
    else player = 0;

  return 0;

}


