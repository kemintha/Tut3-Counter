//Creating a class TicTacToe to play game
//Author: K Naidoo, 15/03/15

#include <iostream>
#include <string>
#include "TicTacToe.hpp"
using namespace std;

int main()
{
	TicTacToe game;
	
	int row = 0;
	int column = 0;
	int again = 1;
	game.setplayer(2);
	while (again == 1)
	{
		while (game.isWon() == 3) //Allows play if availible spaces on board
		{
			if (game.getplayer() == 1)
				game.setplayer(2);
			else
				game.setplayer(1);
			game.requestMove(row, column); //Asks player for move
			while (game.move(row, column) == false) //If move wasnt valid, asks again until is valid
			{
				cout << "Your move was invalid. " << endl;
				game.requestMove(row, column);
			}
			game.move(row, column); //Implements valid move
			game.print(); //Prints board with latest move added
			
			
		}
		if (game.isWon() == 4)
			cout << "The game is a draw." << endl;
		else
			cout << "Player " << game.getplayer() << " has won the game!" << endl;
		cout << "Would you like to play again? (Yes or No)" << endl;
		string decide;
		cin >> decide;
		if (decide == "Yes")
			game.restart();
		else
			again = 0;
		game.setplayer(2);
	}
	return 0;
}

