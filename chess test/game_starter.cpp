#include "header_test.h"
/*ChessBoard::ChessBoard()
{
	
}*/

ChessBoard::ChessBoard(){
	//board
	board_changename.texture.loadFromFile("chess board.jpg");
	board_changename.square.setTexture(&board_changename.texture);
	board_changename.square.setSize(Vector2f(512, 512));
	board_changename.square.setPosition(Vector2f(64 * 0, 64 * 0));

	//black king
	blackPieces[3].texture.loadFromFile("black king.png");
	blackPieces[3].value = -4;
	blackPieces[3].square.setTexture(&blackPieces[3].texture);
	blackPieces[3].square.setSize(Vector2f(64, 64));
	blackPieces[3].place.x = 3;
	blackPieces[3].place.y = 0;
	blackPieces[3].square.setPosition(Vector2f(64 * blackPieces[3].place.x, 64 * blackPieces[3].place.y));
	black_board[blackPieces[3].place.x + (8 * blackPieces[3].place.y)] = 100;
	
	//black queen
	blackPieces[4].texture.loadFromFile("black queen.png");
	blackPieces[4].value = -5;
	blackPieces[4].square.setTexture(&blackPieces[4].texture);
	blackPieces[4].square.setSize(Vector2f(64, 64));
	blackPieces[4].place.x = 4;
	blackPieces[4].place.y = 0;
	blackPieces[4].square.setPosition(Vector2f(64 * blackPieces[4].place.x, blackPieces[4].place.y));
	//black bishop
	blackPieces[2].texture.loadFromFile("black bishop.png");
	blackPieces[2].value = -3;
	blackPieces[2].square.setTexture(&blackPieces[2].texture);
	blackPieces[2].square.setSize(Vector2f(64, 64));
	blackPieces[2].place.x = 2;
	blackPieces[2].place.y = 0;
	blackPieces[2].square.setPosition(Vector2f(64 * blackPieces[2].place.x, blackPieces[2].place.y));
	blackPieces[5].value = -6;
	blackPieces[5].square.setTexture(&blackPieces[2].texture);
	blackPieces[5].square.setSize(Vector2f(64, 64));
	blackPieces[5].place.x = 5;
	blackPieces[5].place.y = 0;
	blackPieces[5].square.setPosition(Vector2f(64 * blackPieces[5].place.x, blackPieces[5].place.y));
	//black knight
	blackPieces[1].texture.loadFromFile("black knight.png");
	blackPieces[1].value = -2;
	blackPieces[1].square.setTexture(&blackPieces[1].texture);
	blackPieces[1].square.setSize(Vector2f(64, 64));
	blackPieces[1].place.x = 1;
	blackPieces[1].place.y = 0;
	blackPieces[1].square.setPosition(Vector2f(64 * blackPieces[1].place.x, blackPieces[1].place.y));
	blackPieces[6].value = -7;
	blackPieces[6].square.setTexture(&blackPieces[1].texture);
	blackPieces[6].square.setSize(Vector2f(64, 64));
	blackPieces[6].place.x = 6;
	blackPieces[6].place.y = 0;
	blackPieces[6].square.setPosition(Vector2f(64 * blackPieces[6].place.x, blackPieces[6].place.y));
	//black rook
	blackPieces[0].texture.loadFromFile("black rook.png");
	blackPieces[0].value = -1;
	blackPieces[0].square.setTexture(&blackPieces[0].texture);
	blackPieces[0].square.setSize(Vector2f(64, 64));
	blackPieces[0].place.x = 0;
	blackPieces[0].place.y = 0;
	blackPieces[0].square.setPosition(Vector2f(64 * blackPieces[0].place.x, blackPieces[0].place.y));
	blackPieces[7].value = -8;
	blackPieces[7].square.setTexture(&blackPieces[0].texture);
	blackPieces[7].square.setSize(Vector2f(64, 64));
	blackPieces[7].place.x = 7;
	blackPieces[7].place.y = 0;
	blackPieces[7].square.setPosition(Vector2f(64 * blackPieces[7].place.x, blackPieces[7].place.y));
	//black pawn
	blackPieces[8].texture.loadFromFile("pawn.png");
	for (int i = 0; i < 8; i++)
	{
		blackPieces[8 + i].value = -9-i;
		blackPieces[8 + i].square.setTexture(&blackPieces[8].texture);
		blackPieces[8 + i].square.setSize(Vector2f(64, 64));
		blackPieces[8+i].place.x = i;
		blackPieces[8+i].place.y = 1;
		blackPieces[8 + i].square.setPosition(Vector2f(64 * blackPieces[8 + i].place.x, 64* blackPieces[8 + i].place.y));

	}

	//white king
	whitePieces[3].texture.loadFromFile("white king.png");
	whitePieces[3].value = 4;
	whitePieces[3].square.setTexture(&whitePieces[3].texture);
	whitePieces[3].square.setSize(Vector2f(64, 64));
	whitePieces[3].place.x = 3;
	whitePieces[3].place.y = 7;
	whitePieces[3].square.setPosition(Vector2f(64 * 3, 64 * 7));
	white_board[3 + (8*7)] = 100;
	//white queen
	whitePieces[4].texture.loadFromFile("white queen.png");
	whitePieces[4].value = 5;
	whitePieces[4].square.setTexture(&whitePieces[4].texture);
	whitePieces[4].square.setSize(Vector2f(64, 64));
	whitePieces[4].place.x = 4;
	whitePieces[4].place.y = 7;
	whitePieces[4].square.setPosition(Vector2f(64 * 4, 64 * 7));
	//white bishop
	whitePieces[2].texture.loadFromFile("white bishop.png");
	whitePieces[2].value = 3;
	whitePieces[2].square.setTexture(&whitePieces[2].texture);
	whitePieces[2].square.setSize(Vector2f(64, 64));
	whitePieces[2].place.x = 2;
	whitePieces[2].place.y = 7;
	whitePieces[2].square.setPosition(Vector2f(64 * 2, 64 * 7));
	whitePieces[5].value = 6;
	whitePieces[5].square.setTexture(&whitePieces[2].texture);
	whitePieces[5].square.setSize(Vector2f(64, 64));
	whitePieces[5].place.x = 5;
	whitePieces[5].place.y = 7;
	whitePieces[5].square.setPosition(Vector2f(64 * 5, 64 * 7));
	//white knight
	whitePieces[1].texture.loadFromFile("white knight.png");
	whitePieces[1].value = 2;
	whitePieces[1].square.setTexture(&whitePieces[1].texture);
	whitePieces[1].square.setSize(Vector2f(64, 64));
	whitePieces[1].place.x = 1;
	whitePieces[1].place.y = 7;
	whitePieces[1].square.setPosition(Vector2f(64 * 1, 64 * 7));
	whitePieces[6].value = 7;
	whitePieces[6].square.setTexture(&whitePieces[1].texture);
	whitePieces[6].square.setSize(Vector2f(64, 64));
	whitePieces[6].place.x = 6;
	whitePieces[6].place.y = 7;
	whitePieces[6].square.setPosition(Vector2f(64 * 6, 64 * 7));
	//white rook
	whitePieces[0].texture.loadFromFile("white rook.png");
	whitePieces[0].value = 1;
	whitePieces[0].square.setTexture(&whitePieces[0].texture);
	whitePieces[0].square.setSize(Vector2f(64, 64));
	whitePieces[0].place.x = 0;
	whitePieces[0].place.y = 7;
	whitePieces[0].square.setPosition(Vector2f(64 * 0, 64 * 7));
	whitePieces[7].value = 8;
	whitePieces[7].square.setTexture(&whitePieces[0].texture);
	whitePieces[7].square.setSize(Vector2f(64, 64));
	whitePieces[7].place.x = 7;
	whitePieces[7].place.y = 7;
	whitePieces[7].square.setPosition(Vector2f(64 * 7, 64 * 7));

	//white pawn
	whitePieces[8].texture.loadFromFile("white pawn.png");
	for (int i = 0; i < 8; i++)
	{
		whitePieces[8 + i].value = 9+i;
		whitePieces[8 + i].square.setTexture(&whitePieces[8].texture);
		whitePieces[8 + i].square.setSize(Vector2f(64, 64));
		whitePieces[8 + i].place.x = i;
		whitePieces[8 + i].place.y = 6;
		whitePieces[8 + i].square.setPosition(Vector2f(64 * i, 64*6));

	}
	


}

ChessBoard::~ChessBoard()
{
}

void ChessBoard::create_board()
{

	sf::RenderWindow window(sf::VideoMode(512, 512), "Chess The Game Of Kings!", Style::Close);
	int arr[8][8];
	
	
	//Hold for move of pieces
	int x0 = -1, x1 = -1, y0 = -1, y1 = -1;
	bool Hold = true;
	
	

	while (window.isOpen()) {

		Event event;
		while (window.pollEvent(event)) {


			switch (event.type) {
			case Event::Closed:
				window.close();
				break;
			case Event::MouseButtonPressed:
			{
				ChessBoard::white_board_check();
				ChessBoard::view_w();
				switch (event.key.code)
				{
				case Mouse::Left:
				{
					
					Vector2i mouse_ps = Mouse::getPosition(window);
					int i, j;

					i = (static_cast<float>(mouse_ps.x) / 64);
					j = ((static_cast<float>(mouse_ps.y)) / 64);
					if (Hold && arr_value(i,j) !=0) {
						x0 = i;
						y0 = j;
						Hold = !Hold;
					}
					else {
						if (arr_value(i, j) == 0)
						{
							if (move(x0, y0, i, j))
							{

								Hold = !Hold;
							}
						}
						else {
							if (move(x0, y0, i, j))
							{
								if (temp > 0)
								{
									whitePieces[temp - 1].square.setPosition(-100, -100);
									whitePieces[temp - 1].value = 0;
									//add something here find the value of this piece in white_board and make it equal to zero like here
									whitePieces[temp - 1].place.x = -1;
									whitePieces[temp - 1].place.y = -1;
								}
								else {
									cout << endl << endl << temp << endl << "helllllllllllllo";
									blackPieces[abs(temp) - 1].value = 0;
									//add something here find the value of this piece in black_board and make it equal to zero like here
									blackPieces[abs(temp) - 1].place.x = -1;
									blackPieces[abs(temp) - 1].place.y = -1;
									blackPieces[abs(temp) - 1].square.setPosition(-100, -100);
								}
								Hold = !Hold;
							}
						}

					}
					break;
				}

				break;
				}
			}
			}
			window.clear();
			window.draw(board_changename.square);
			//draw black pieces
			for (int i = 0; i < 8; i++)
			{
				window.draw(blackPieces[i].square);
			}
				//pawn draw
			for (int i = 0; i < 8; i++)
			{
				window.draw(blackPieces[8 + i].square);
			}
			//draw white pieces
			for (int i = 0; i < 8; i++)
			{
				window.draw(whitePieces[i].square);
			}
			//pawn draw
			for (int i = 0; i < 8; i++)
			{
				window.draw(whitePieces[8 + i].square);
			}

			
			window.display();


		}

	}
}


//opazity
/*
1 generate all valid moves
2 move all moves
3 generate all opponents moves
4 check if opponent moves block the king's moves
5 if so it's not a valid move
*/
// always have kings locations