//Source file for class TicTacToe

#include <iostream>
#include <string>
#include "TicTacToe.hpp"

using namespace std;

TicTacToe::TicTacToe() //Constructor, initializes board to blank, player to 1
{
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			board[i][j] = '_';
		}
	}
	player = 1;
}

TicTacToe::~TicTacToe() //Destructor for class
{
}

int TicTacToe::getplayer() 
{ 
	return player;
}

void TicTacToe::setplayer(int any)
{
	player = any;
}

void TicTacToe::restart() //Initializes board to blank, player to 1
{
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			board[i][j] = '_';
		}
	}
	player = 1;
}

bool TicTacToe::move(int row, int column) //Determines if move is legal, and implements move if it is.
{
	if (row < 0 || row > 2 || column < 0 || column > 2) //If move made is not on the board
		return false;
	else if (board[row][column] != '_') //If space to move to is already occupied
		return false;
	else //Implements valid move
	{
		if (player == 1)
		{
			board[row][column] = 'X';
		}
		else if (player == 2)
		{
			board[row][column] = 'O';
		}
		return true;
	}

}


void TicTacToe::print()
{
	cout << "    1  2  3 " << endl << "------------";
	cout << endl << "A| ";
	for (int i = 0; i <= 2; i++)
	{
		cout << ' ' << board[0][i] << ' ';
	}
	cout << endl << "B| ";
	for (int i = 0; i <= 2; i++)
	{
		cout << ' ' << board[1][i] << ' ';
	}
	cout << endl << "C| ";
	for (int i = 0; i <= 2; i++)
	{
		cout << ' ' << board[2][i] << ' ';
	}
	cout << endl;


}


int TicTacToe::isWon()
{
	//If a player won, returns player number

	char symbol;
	if (player == 1)
		symbol = 'X';
	else
		symbol = 'Y';
	
	for (int i = 0; i < 2; i++)
	{
		if ((board[0][i] == symbol) && (board[1][i] == symbol) && (board[2][i] == symbol))
			return player;
		if ((board[i][0] == symbol) && (board[i][1] == symbol) && (board[i][2] == symbol))
			return player;
	}
	if ((board[0][0] == symbol) && (board[1][1] == symbol) && (board[2][2] == symbol))
		return player;
	if ((board[0][2] == symbol) && (board[1][1] == symbol) && (board[0][2] == symbol))
		return player;

	//Checks if blank spaces still on board
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			if (board[i][j] == '_')
			{
				return 3; //Signifies game still in progress
			}
		}
	}

	return 4; //Signifies game is over as a draw
}


void TicTacToe::requestMove(int &row, int &column)
{
	char x;
	int y;
	cout << "Player " << player << ", please enter a row (A - C)>>   ";
	cin >> x;
	cout << "Player " << player << ", please enter a column (1 - 3)>>   ";
	cin >> y;
	row = 4;
	column = 4;
	if (x == 'A')
		row = 0;
	if (x == 'B')
		row = 1;
	if (x == 'C')
		row = 2;
	column = y - 1;

}
 