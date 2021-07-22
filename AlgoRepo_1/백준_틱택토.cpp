#include <iostream>
#include <string>

using namespace std;

char board[3][3];

int oCount, xCount;

void CheckTictactoe()
{
	int xWin = 0, oWin = 0;
	if (board[0][0] == board[0][1] && board[0][1] == board[0][2])
	{
		if (board[0][0] == 'X')
			xWin++;
		else if (board[0][0] == 'O')
			oWin++;
	}

	if (board[1][0] == board[1][1] && board[1][1] == board[1][2])
	{
		if (board[1][0] == 'X')
			xWin++;
		else if (board[1][0] == 'O')
			oWin++;
	}

	if (board[2][0] == board[2][1] && board[2][1] == board[2][2])
	{
		if (board[2][0] == 'X')
			xWin++;
		else if (board[2][0] == 'O')
			oWin++;
	}

	if (board[0][0] == board[1][0] && board[1][0] == board[2][0])
	{
		if (board[0][0] == 'X')
			xWin++;
		else if (board[0][0] == 'O')
			oWin++;
	}

	if (board[0][1] == board[1][1] && board[1][1] == board[2][1])
	{
		if (board[0][1] == 'X')
			xWin++;
		else if (board[0][1] == 'O')
			oWin++;
	}

	if (board[0][2] == board[1][2] && board[1][2] == board[2][2])
	{
		if (board[0][2] == 'X')
			xWin++;
		else if (board[0][2] == 'O')
			oWin++;
	}

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		if (board[0][0] == 'X')
			xWin++;
		else if (board[0][0] == 'O')
			oWin++;
	}

	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		if (board[0][2] == 'X')
			xWin++;
		else if (board[0][2] == 'O')
			oWin++;
	}

	if (!xWin && !oWin)
	{
		if (xCount + oCount == 9)
			cout << "valid\n";
		else
			cout << "invalid\n";
	}
	else if (xWin == 1 && !oWin)
	{
		if (xCount - oCount == 1)
			cout << "valid\n";
		else
			cout << "invalid\n";
	}
	else if (xWin == 2 && !oWin)
	{
		if (xCount - oCount == 1)
			cout << "valid\n";
		else
			cout << "invalid\n";
	}
	else if (!xWin && oWin == 1)
	{
		if (xCount == oCount)
			cout << "valid\n";
		else
			cout << "invalid\n";
	}
	else if (!xWin && oWin == 2)
	{
		if (xCount - oCount == 1)
			cout << "valid\n";
		else
			cout << "invalid\n";
	}
	else
		cout << "invalid\n";

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;

	while (1)
	{
		cin >> s;
		if (s == "end")
			break;

		oCount = 0, xCount = 0;
		for (int i = 0; i < 9; i++)
		{
			board[i / 3][i % 3] = s[i];

			if (s[i] == 'X')
				xCount++;
			else if (s[i] == 'O')
				oCount++;
		}

		if (oCount > xCount)
			cout << "invalid\n";
		else
			CheckTictactoe();
	}

	return 0;
}