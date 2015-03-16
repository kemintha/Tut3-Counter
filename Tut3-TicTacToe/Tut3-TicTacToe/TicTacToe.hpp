//Header file for class TicTacToe

#pragma once
#ifndef TICTACTOE_H
#define TICTACTOE_H
using namespace std;

class TicTacToe
{
private:
	char board[3][3]; //Declares array of characters as board for game
	int player; //Signifies which player is in use
public:
	TicTacToe(); //Constructor and destructor declarations
	~TicTacToe();
	int getplayer(); //Accessor for current player variable
	void setplayer(int);

	void restart();
	bool move(int, int); //Allows inputs of x and y coordinates 
	void print();
	int isWon();
	void requestMove(int &, int &);
	
};

#endif