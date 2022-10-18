#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
using namespace sf;
using namespace std;
// like class qwith fields
struct position
{
	int x, y;

};
struct Piece {
	int value;
	Texture texture;
	RectangleShape square;
	bool isMoved = false;
	position place;

};

/*:*/


class ChessBoard {
	

public:
	ChessBoard();
	~ChessBoard();
	int board[64] = {
   -1,-2,-3,-4,-5,-6,-7,-8,
   -9,-10,-11,-12, -13,-14, -15,-16,
	0, 0, 0, 0,0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	9,10,11,12, 13,14, 15,16,
	1, 2, 3, 4, 5, 6, 7, 8
	};
	int temp = 0;
	bool white_check_mate = false;
	bool black_check_mate = false;
	int white_board[64] = {0};
	int black_board[64] = {0};
	bool turn = true;
	int v_arr[8] = { 0 };

	/*
	* this function check if the king have all non-zero value surrounding him
	*/
	/*
	void w_check(int x0,int y0)
	{
	int counter = 0;
	for (int i = 0; i < 3; i++)
	{
		if (x0 + 1 <= 7 && x0 - 1 >= 0 && y0 - 1 > 0 && y0 + 1 <= 7) {
			if (white_board[(x0 - 1) + (((y0 - 1) + i) * 8)] != 0) { counter++; }
			if (white_board[(x0 + 1) + (((y0 - 1) + i) * 8)] != 0) { counter++; }
			if (white_board[x0 + (y0 - 1) * 8])
				{ counter++; }
			if (white_board[x0 + (y0 + 1) * 8])
			{ counter++; }
		}
	}
	*/
	


	//FUN move piece
	bool move(int x0, int y0, int x1, int y1);
	void view();
	bool arr_empty(int x, int y);
	int arr_value(int x, int y);
	Piece blackPieces[16];
	Piece whitePieces[16];
	Piece board_changename; 
	bool piece_restrict(int x0, int y0, int x1, int y1);
	int move_vector(int x0, int y0, int x1, int y1, int arr_value);
	int obstacle(int x0, int y0,int move_vector);
	int num_moves(int x0, int y0, int x1, int y1);
	bool jump_restrict(int num_moves, int obstacle);
	void eating_White_board(int x0, int y0);
	void view_w();




	bool white_board_check();
	bool black_board_check();

	//FUN create main board
	//when we press on empty we can't select item, pleace make a reselect funtion and glowing piece
	void create_board();

};