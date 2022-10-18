#include "header_test.h"
//successful
bool ChessBoard::piece_restrict(int x0, int y0, int x1, int y1) {

	//////////////////////
	/// 
	///
	///make the if only on pawns because all pieces move alike
	/// rook like rook bishop like boshop, black queen like white queen
	///
	///
	///
	/////////////////////

	if (arr_value(x0, y0) > 0)
	{
		if (turn)
		{
			switch (arr_value(x0, y0))
			{
			case 9:
			case 10:
			case 11:
			case 12:
			case 13:
			case 14:
			case 15:
			case 16:
			{
				// white pawn
				if (y0 - y1 == 1 && x1 - x0 == 0 || y0 - y1 == 2 && x1 - x0 == 0 && !whitePieces[(arr_value(x0, y0) - 1)].isMoved)
				{
					//when moves isMoved always true
					if (!whitePieces[(arr_value(x0, y0) - 1)].isMoved)
					{
						whitePieces[(arr_value(x0, y0) - 1)].isMoved = !whitePieces[(arr_value(x0, y0) - 1)].isMoved;
					}
					turn = false;
					return true;
				}
				else {
					return false;
				}
				break;
			}
			case 1:
			case 8:
			{
				//rook
				if (x1 - x0 != 0 && y1 - y0 == 0 || x1 - x0 == 0 && y1 - y0 != 0)
				{
					turn = false;
					return true;
				}
				else {
					return false;
				}
			}
			case 2:
			case 7:
			{
				//knight
				if (abs(x1 - x0) == 2 && abs(y1 - y0) == 1 || abs(x1 - x0) == 1 && abs(y1 - y0) == 2)
				{
					turn = false;
					return true;
				}
				else {
					return false;
				}
				break;
			}
			case 3:
			case 6:
			{
				//bishop
				if (abs(x1 - x0) == abs(y1 - y0))
				{
					turn = false;
					return true;
				}
				else {
					return false;
				}
				break;
			}
			case 4:
			{
				//king
				if (abs(x1 - x0) == 1 && abs(y1 - y0) == 1 || abs(x1 - x0) == 1 && abs(y1 - y0) == 0 || abs(x1 - x0) == 0 && abs(y1 - y0) == 1)
				{
					turn = false;
					return true;
				}
				else {
					return false;
				}
				break;
			}
			case 5:
			{
				//queen
				if (abs(x1 - x0) == abs(y1 - y0) || x1 - x0 != 0 && y1 - y0 == 0 || x1 - x0 == 0 && y1 - y0 != 0)
				{
					turn = false;
					return true;
				}
				else {
					return false;
				}
				break;
			}
			}
		}
		else
		{
			return false;
		}
	}
	else if (arr_value(x0, y0) < 0) {
		if (turn == false)
		{
			switch (arr_value(x0, y0))
			{
				//black pawns
			case -9:
			case -10:
			case -11:
			case -12:
			case -13:
			case -14:
			case -15:
			case -16:
			{
				if (y1 - y0 == 1 && x1 - x0 == 0 || y1 - y0 == 2 && x1 - x0 == 0 && !blackPieces[abs((arr_value(x0, y0)) - 1)].isMoved)
				{
					if (!blackPieces[abs((arr_value(x0, y0)) - 1)].isMoved)
					{
						blackPieces[abs((arr_value(x0, y0)) - 1)].isMoved = !blackPieces[abs((arr_value(x0, y0)) - 1)].isMoved;
					}
					turn = true;
					return true;
				}
				else {
					return false;
				}
				break;
			}
			case -1:
			case -8:
			{
				//rook
				if (x1 - x0 != 0 && y1 - y0 == 0 || x1 - x0 == 0 && y1 - y0 != 0)
				{
					turn = true;
					return true;
				}
				else {
					return false;
				}
			}
			case -2:
			case -7:
			{
				//knight
				if (abs(x1 - x0) == 2 && abs(y1 - y0) == 1 || abs(x1 - x0) == 1 && abs(y1 - y0) == 2)
				{
					turn = true;
					return true;
				}
				else {
					return false;
				}
				break;
			}
			case -3:
			case -6:
			{
				//bishop
				if (abs(x1 - x0) == abs(y1 - y0))
				{
					turn = true;
					return true;
				}
				else {
					return false;
				}
				break;
			}
			case -4:
			{
				//king
				if (abs(x1 - x0) == 1 && abs(y1 - y0) == 1 || abs(x1 - x0) == 1 && abs(y1 - y0) == 0 || abs(x1 - x0) == 0 && abs(y1 - y0) == 1)
				{
					turn = true;
					return true;
				}
				else {
					return false;
				}
				break;
			}
			case -5:
			{
				//queen
				if (abs(x1 - x0) == abs(y1 - y0) || x1 - x0 != 0 && y1 - y0 == 0 || x1 - x0 == 0 && y1 - y0 != 0)
				{
					turn = true;
					return true;
				}
				else {
					return false;
				}
				break;
			}
			}
		}
		else
		{
			return false;
		}
	}


}
//successful add knight as value in the parameters and put it and the if condition
int ChessBoard::move_vector(int x0, int y0, int x1, int y1, int arr_value) {
	int deltax = x1 - x0;
	int deltay = y1 - y0;
	//diagonal
	if (arr_value == -2 && arr_value == -7 && arr_value == 7 && arr_value == 2) { return 9; }
	else if (abs(deltax)==abs(deltay))
	{
		if (deltay > 0)
		{
			if (deltax > 0)
			{
				cout << "moves digonal to down right";
					return 4;
			}
			else {
				cout << "moves digonal to down left";
				return 6;
			}
		}
		else {
			if (deltax > 0)
			{
				cout << "moves digonal to up right";
				return 2;
			}
			else {
				cout << "moves digonal to up left";
				return 8;
			}
		}
	}
	else if (deltax != 0 && deltay == 0 || deltay != 0 && deltax == 0) {
		if (deltax > 0 && deltay == 0)
		{
			cout << "moves right";
			return 3;
		}else if (deltax < 0 && deltay == 0)
		{
			cout << "moves left";
			return 7;
		}else if (deltay < 0)
		{
			cout << "moves up";
			return 1;
		}else if (deltay > 0 )
		{
			cout << "moves down";
			return 5;
		}
	
	}

}
// remove break after return
//successful
int ChessBoard::obstacle(int x0, int y0, int move_vector) {
	//number of places that have zero value
	//this function return the position of obstacle
	int counter = 1;
	switch (move_vector)
	{
		case 1:
		{
			//up
			int i = 1;
			while ((y0 - i) >= 0)
			{
				if (board[(x0 + ((y0 - i) * 8))] != 0)
				{
					temp = board[(x0 + ((y0 - i) * 8))];
					break;
				}
				else if (board[(x0 + ((y0 - i) * 8))] == 0){
					counter++;
				 }
				i++;
				cout << endl << "move_vector up value of position :" << counter << endl;

			}

			return counter;
			break;
		}
		case 5:
		{
			//down
			int i = 1;
			while (y0 + i <= 7)
			{
				if (board[(x0 + ((y0 + i) * 8))] != 0)
				{
					temp = board[(x0 + ((y0 - i) * 8))];

					break;

				}
				else if (board[(x0 + ((y0 + i) * 8))] == 0) {
					counter++;
					
				}
				i++;
			}

			return counter;
			break;
		}
		case 3:
		{
			//right
			int i = 1;
			while (x0 + i <= 7)
			{
				if (board[((x0 + i) + (y0 * 8))] != 0)
				{
					temp = board[(x0 + ((y0 - i) * 8))];
					break;

				}
				else if (board[((x0 + i) + (y0 * 8))] == 0){
					counter++;
				 }
				i++;
			}

			return counter;
			break;
		}
		case 7:
		{
			//left
			int i = 1;
			while (x0 - i >= 0)
			{
				
				if (board[((x0 - i) + (y0 * 8))] != 0)
				{
					temp = board[(x0 + ((y0 - i) * 8))];
					break;
				}
				else if (board[((x0 - i) + (y0 * 8))] == 0) {
					counter++;				
				}
				i++;
			}

			return counter;
			break;
		}
		case 4:
		{
			//down right
			int i = 1;
			while (x0 + i <= 7 && y0 + i <= 7)
			{
				if (board[((x0 + i) + ((y0 + i) * 8))] != 0)
				{
					temp = board[(x0 + ((y0 - i) * 8))];
					break;
				}
				else if (board[((x0 + i) + ((y0 + i) * 8))] == 0) { counter++; }
				i++;
			}

			return counter;
			break;
		}
		case 2:
		{
			//up right
			int i = 1;
			while (x0 + i <= 7 && y0 - i >= 0)
			{
				if (board[((x0 + i) + ((y0 - i) * 8))] != 0)
				{
					temp = board[(x0 + ((y0 - i) * 8))];
					break;

				}
				else if (board[((x0 + i) + ((y0 - i) * 8))] == 0) { counter++; }
				i++;
			}

			return counter;
			break;
		}
		case 8:
		{
			//up left
			int i = 1;
			while (x0 - i >= 0 && y0 - i >= 0)
			{
				if (board[((x0 - i) + ((y0 - i) * 8))] != 0)
				{
					temp = board[(x0 + ((y0 - i) * 8))];
					break;

				}
				else if(board[((x0 - i) + ((y0 - i) * 8))] == 0) {
					counter++; }
				i++;
			}

			return counter;
			break;
		}
		case 6:
		{
			//down left
			int i = 1;
			while (x0 - i >= 0 && y0 + i <= 7)
			{
				if (board[((x0 - i) + ((y0 + i) * 8))] != 0)
				{
					temp = board[(x0 + ((y0 - i) * 8))];
					break;
				}
				else if (board[((x0 - i) + ((y0 + i) * 8))] == 0) {
					counter++;
				}
				i++;
			}

			return counter;
			break;
		}
	}
}
//successful
int ChessBoard::num_moves(int x0, int y0, int x1, int y1) {
	if (abs(x1-x0) == abs(y1 - y0))
	{
		return abs(x1 - x0);
	}
	else if (x1 - x0 != 0) {
		return abs(x1 - x0);
	}
	else if (y1 - y0 != 0) {
		return abs(y1 - y0);
	}
}

bool ChessBoard::jump_restrict(int num_move, int obstacle) {
	if (abs(num_move) > obstacle)
	{
		return false;
	}
	else {
		return true;
	}

}

bool ChessBoard::move(int x0, int y0, int x1, int y1) {
	//normal moving function
	if (arr_value(x1, y1) == 0)
	{
		//knight move
		if (arr_value(x0, y0) == 2 || arr_value(x0, y0) == -2 || arr_value(x0, y0) == 7 || arr_value(x0, y0) == -7) {

			if (arr_empty(x1, y1) && piece_restrict(x0, y0, x1, y1))
			{
				int value = board[x0 + (y0 * 8)];
				board[x1 + (y1 * 8)] = board[x0 + (y0 * 8)];
				board[x0 + (y0 * 8)] = 0;
				if (board[x1 + (y1 * 8)] < 0)
				{
					blackPieces[abs(value) - 1].place.x = x1;
					blackPieces[abs(value) - 1].place.y = y1;
					blackPieces[abs(value) - 1].square.setPosition(blackPieces[abs(value) - 1].place.x * 64, blackPieces[abs(value) - 1].place.y * 64);

				}
				else {
					whitePieces[abs(value) - 1].place.x = x1;
					whitePieces[abs(value) - 1].place.y = y1;
					whitePieces[abs(value) - 1].square.setPosition(whitePieces[abs(value) - 1].place.x * 64, whitePieces[abs(value) - 1].place.y * 64);

				}
				return true;
			}
			else { return false; }
		}
		//move when empty
		else if (arr_empty(x1, y1) && piece_restrict(x0, y0, x1, y1) && jump_restrict(num_moves(x0, y0, x1, y1), obstacle(x0, y0, move_vector(x0, y0, x1, y1, arr_value(x0, x1)))))
		{

			int value = board[x0 + (y0 * 8)];
			board[x1 + (y1 * 8)] = value;
			board[x0 + (y0 * 8)] = 0;
			if (board[x1 + (y1 * 8)] < 0)
			{
				blackPieces[abs(value) - 1].place.x = x1;
				blackPieces[abs(value) - 1].place.y = y1;
				blackPieces[abs(value) - 1].square.setPosition(blackPieces[abs(value) - 1].place.x * 64, blackPieces[abs(value) - 1].place.y * 64);

			}
			else {
				whitePieces[abs(value) - 1].place.x = x1;
				whitePieces[abs(value) - 1].place.y = y1;
				whitePieces[abs(value) - 1].square.setPosition(whitePieces[abs(value) - 1].place.x * 64, whitePieces[abs(value) - 1].place.y * 64);

			}

			return true;
		}
		//when it is empty and u move wrong [jump or not in the domain of the piece]
		else { return false; }
	}
	//eating piece
	else if (arr_value(x0, y0) > 0 && arr_value(x1, y1) < 0 || arr_value(x0, y0) < 0 && arr_value(x1, y1) > 0 ) {
		//all pieces without pawns
		if ( piece_restrict(x0, y0, x1, y1) && jump_restrict(num_moves(x0, y0, x1, y1), obstacle(x0, y0, move_vector(x0, y0, x1, y1, arr_value(x0, x1)))) && arr_value(x0,y0) < 9 && arr_value(x0,y0) > -9)
		{
			int value = board[x0 + (y0 * 8)];
			temp = board[x1 + (y1 * 8)];
			cout << endl << temp << endl << endl;
			board[x1 + (y1 * 8)] = value;
			board[x0 + (y0 * 8)] = 0;
			//whne moving a black piece
			if (value < 0)
			{
				blackPieces[abs(value) - 1].place.x = x1;
				blackPieces[abs(value) - 1].place.y = y1;
				blackPieces[abs(value) - 1].square.setPosition(blackPieces[abs(value) - 1].place.x * 64, blackPieces[abs(value) - 1].place.y * 64);

			}
			//when moving a white piece
			else {

				whitePieces[abs(value) - 1].place.x = x1;
				whitePieces[abs(value) - 1].place.y = y1;
				whitePieces[abs(value) - 1].square.setPosition(whitePieces[abs(value) - 1].place.x * 64, whitePieces[abs(value) - 1].place.y * 64);

			}

			return true;
		}
		
		//eating with pawn 
			//black eating piece
		else if (abs(x1-x0) == 1 && y1-y0 == 1 && arr_value(x0,y0) < -9) {
			int value = board[x0 + (y0 * 8)];
			temp = board[x1 + (y1 * 8)];
			cout << endl << temp << endl << endl;
			board[x1 + (y1 * 8)] = value;
			board[x0 + (y0 * 8)] = 0;
			
				blackPieces[abs(value) - 1].place.x = x1;
				blackPieces[abs(value) - 1].place.y = y1;
				blackPieces[abs(value) - 1].square.setPosition(blackPieces[abs(value) - 1].place.x * 64, blackPieces[abs(value) - 1].place.y * 64);

				turn = true;
			return true;
		}
		//white
		else if (abs(x1 - x0) == 1 && y0 - y1 == 1 && arr_value(x0,y0) >= 9 ) {
			int value = board[x0 + (y0 * 8)];
			temp = board[x1 + (y1 * 8)];
			cout << endl << temp << endl << endl;
			board[x1 + (y1 * 8)] = value;
			board[x0 + (y0 * 8)] = 0;
			
				whitePieces[abs(value) - 1].place.x = x1;
				whitePieces[abs(value) - 1].place.y = y1;
				whitePieces[abs(value) - 1].square.setPosition(whitePieces[abs(value) - 1].place.x * 64, whitePieces[abs(value) - 1].place.y * 64);

				turn = false;
			return true;
		}
		else { return false; }


	}else {
		return false;
	}

}

void ChessBoard::eating_White_board(int x0, int y0)
{
	for (int j = 0; j < 8; j++)
	{
		if (j > 0)
		{
			switch (v_arr[j])
			{
			case 1:
			{
				//up
				int i = 1;
				while ((y0 - i) >= 0)
				{
					if (white_board[(x0 + ((y0 - i) * 8))] != 0)
					{
						temp = white_board[(x0 + ((y0 - i) * 8))];
						break;
					}
					else if (white_board[(x0 + ((y0 - i) * 8))] == 0) {
						white_board[(x0 + ((y0 - i) * 8))] = -1;
					}
					i++;

				}
				break;
			}
			case 5:
			{
				//down
				int i = 1;
				while (y0 + i <= 7)
				{
					if (white_board[(x0 + ((y0 + i) * 8))] != 0)
					{
						temp = white_board[(x0 + ((y0 - i) * 8))];

						break;

					}
					else if (white_board[(x0 + ((y0 + i) * 8))] == 0) {
						white_board[((x0 - i) + ((y0 + i) * 8))] = -1;
					}
					i++;
				}
				break;
			}
			case 3:
			{
				//right
				int i = 1;
				while (x0 + i <= 7)
				{
					if (white_board[((x0 + i) + (y0 * 8))] != 0)
					{
						temp = white_board[(x0 + ((y0 - i) * 8))];
						break;

					}
					else if (white_board[((x0 + i) + (y0 * 8))] == 0) {
						white_board[((x0 - i) + ((y0 + i) * 8))] = -1;
					}
					i++;
				}
				break;
			}
			case 7:
			{
				//left
				int i = 1;
				while (x0 - i >= 0)
				{

					if (white_board[((x0 - i) + (y0 * 8))] != 0)
					{
						temp = white_board[(x0 + ((y0 - i) * 8))];
						break;
					}
					else if (white_board[((x0 - i) + (y0 * 8))] == 0) {
						white_board[((x0 - i) + ((y0 + i) * 8))] = -1;
					}
					i++;
				}

				break;
			}
			case 4:
			{
				//down right
				int i = 1;
				while (x0 + i <= 7 && y0 + i <= 7)
				{
					if (white_board[((x0 + i) + ((y0 + i) * 8))] != 0)
					{
						temp = white_board[(x0 + ((y0 - i) * 8))];
						break;
					}
					else if (white_board[((x0 + i) + ((y0 + i) * 8))] == 0)
					{
						white_board[((x0 - i) + ((y0 + i) * 8))] = -1;
					}
					i++;
				}

				break;
			}
			case 2:
			{
				//up right
				int i = 1;
				while (x0 + i <= 7 && y0 - i >= 0)
				{
					if (white_board[((x0 + i) + ((y0 - i) * 8))] != 0)
					{
						temp = white_board[(x0 + ((y0 - i) * 8))];
						break;

					}
					else if (white_board[((x0 + i) + ((y0 - i) * 8))] == 0)
					{
						white_board[((x0 - i) + ((y0 + i) * 8))] = -1;
					}
					i++;
				}

				break;
			}
			case 8:
			{
				//up left
				int i = 1;
				while (x0 - i >= 0 && y0 - i >= 0)
				{
					if (white_board[((x0 - i) + ((y0 - i) * 8))] != 0)
					{
						temp = white_board[(x0 + ((y0 - i) * 8))];
						break;

					}
					else if (white_board[((x0 - i) + ((y0 - i) * 8))] == 0) {
						white_board[((x0 - i) + ((y0 + i) * 8))] = -1;
					}
					i++;
				}

				break;
			}
			case 6:
			{
				//down left
				int i = 1;
				while (x0 - i >= 0 && y0 + i <= 7)
				{
					if (white_board[((x0 - i) + ((y0 + i) * 8))] != 0)
					{
						temp = white_board[(x0 + ((y0 - i) * 8))];
						break;
					}
					else if (white_board[((x0 - i) + ((y0 + i) * 8))] == 0) {
						white_board[((x0 - i) + ((y0 + i) * 8))] = -1;
					}
					i++;
				}

				break;
			}
			}
		}
		else
		{
			break;
		}
	}
}

bool ChessBoard::white_board_check() {
	for (int i = 0; i < 16; i++)
	{
		cout << "jhjhh" << endl;
		if (whitePieces[i].value != 0) {
			int white_value = whitePieces[i].value;
			
			break;
			switch (white_value)
			{
			case 1:
			case 8:
				v_arr[0] = {1};
				v_arr[1] = { 3 };
				v_arr[2] = { 5 };
				v_arr[3] = { 7 };
				eating_White_board(whitePieces[i].place.x, whitePieces[i].place.y);
				break;
			case 2:
			case 7:
				break;
			case 3:
			case 6:
				v_arr[0] = { 2 };
				v_arr[1] = { 4 };
				v_arr[2] = { 6};
				v_arr[3] = { 8 };
				break;
			case 5:
				v_arr[0] = { 1 };
				v_arr[1] = { 2 };
				v_arr[2] = { 3 };
				v_arr[3] = { 4 };
				v_arr[4] = { 5 };
				v_arr[5] = { 6 };
				v_arr[6] = { 7 };
				v_arr[7] = { 8 };
				break;
			}
			
		}
	}
	return false;
}

bool ChessBoard::black_board_check() {

	return false;
}


/*
		for (int i = 0; i < 32; i++)
		{
			square[i].setSize(Vector2f(64, 64));
			square[i + 32].setSize(Vector2f(64, 64));
			square[i * 2].setFillColor(Color::Blue);
			square[(i * 2) + 1].setFillColor(Color::White);
		}

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				square[j + (i * 8)].setPosition(64 * j, 64 * i);
			}
		}



		[main window (play,credit,exit)]
[window (take names)]

class pieces {
	int value;
	RectangleShape rc[32];
	void pieces_size() {
		for (int i = 0; i < 32; i++)
		{
			rc[i].setSize(Vector2f(64,64));
		}
	}

};








=====
board [show names, show died pieces]
turns
select-deselect
move - restrict
jump restrict
eating
upgrade
check draw
======
[show winner screen]
*/

