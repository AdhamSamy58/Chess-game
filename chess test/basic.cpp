
#include <iostream>
#include <SFML/Graphics.hpp>
#include "header_test.h"

using namespace sf;
//successful
bool ChessBoard::arr_empty(int x, int y) {
	if (board[x + (y * 8)] == 0)
	{
		return true;
	}
	else {
		return false;
	}
}
//successful
void ChessBoard::view() {
	cout << endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << board[j + (8 * i)] << " ";
		}
		cout << endl;

	}
}
//successful
int ChessBoard::arr_value(int x, int y) {
	return board[x + (y * 8)];
}
void ChessBoard::view_w() {
	cout << endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << white_board[j + (8 * i)] << " ";
		}
		cout << endl;

	}
}







