#include<iostream>
using namespace std;

char board[9] = {};
void clearscreen()
{
	for (int i = 0; i < 40; i++)
	{
		cout << endl;
	}
}
void clearboard()
{
	for (int i = 0; i < 9; i++)
	{
		board[i] = '-';
	}
}
bool win(char player)
{
	const int wins[][3] = { {0,1,2}, {3,4,5},{6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8},{2,4,6} };

	for (int i = 0; i < 8; i++)
	{
		int count = 0;
		for (int j = 0; j < 3; j++)
		{

			if (board[wins[i][j]] == player) count++;

		}
		if (count == 3)
		{
			return true;
		}
	}
	return false;

}

void print_board()
{
	cout << "Game board:" << endl;
	cout << "-" << board[6] << "-|-" << board[7] << "-|-" << board[8] << "-|" << endl;
	cout << "-" << board[3] << "-|-" << board[4] << "-|-" << board[5] << "-|" << endl;
	cout << "-" << board[0] << "-|-" << board[1] << "-|-" << board[2] << "-|" << endl;

}
int get_move()
{
	cout << "Move options: \n";
	cout << "-7-|-8-|-9-|" << endl;
	cout << "-4-|-5-|-6-|" << endl;
	cout << "-1-|-2-|-3-|" << endl;
	cout << "\n";

	print_board();
	cout << "Your move: ";

	int move;
	cin >> move;
	while (move > 9 || move < 1 || board[move - 1] != '-')
	{
		cout << "Please enter correct move (1-9)" << endl;
		cin >> move;
	}
	return move;
}

char get_winner()
{
	int turn = 0;
	while (!win('X') && !win('O'))
	{
		clearscreen();
		int move = get_move();
		cout << "The move you entered is: " << move << endl;
		if (turn % 2 == 0)
		{
			board[move - 1] = 'X';
			if (win('X'))
			{
				cout << "\n !!!!!Congratulations player O!!!!!!!\t ""\n !!!!!You win!!!!! " << endl;
			}
		}

		else
		{
			board[move - 1] = 'O';
			if (win('O'))
			{
				cout << "\n !!!!!Congratulations player O !!!!!!!\t ""\n !!!!!You win!!!!! " << endl;
			}
		}
		turn++;
		if (turn == 10)
		{
			cout << "\n It`s draw!" << endl;
			return 'D';
		}
	}
}
void main()
{
	clearboard();

	char winner = get_winner();
	cout << "\nThe final loyal board is: " << endl;
	cout << "\n"; print_board();

}
