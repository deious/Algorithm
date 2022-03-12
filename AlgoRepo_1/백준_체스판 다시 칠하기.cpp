#include <iostream>
#include <algorithm>

using namespace std;

char board[51][51];
char whiteBoard[8][8] =
{
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W'
};

char blackBoard[8][8] = 
{
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B'
};

int CheckWhite(int x, int y) 
{
	int result = 0;
	for (int i = 0; i < 8; i++) 
	{
		for (int j = 0; j < 8; j++) 
		{
			if (board[x + i][y + j] != whiteBoard[i][j])
				result++;
		}
	}

	return result;
}

int CheckBlack(int x, int y) 
{
	int result = 0;
	for (int i = 0; i < 8; i++) 
	{
		for (int j = 0; j < 8; j++) 
		{
			if (board[x + i][y + j] != blackBoard[i][j])
				result++;
		}
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N, M, result = 64;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	int wCount = 0, bCount = 0;
	for (int i = 0; i <= N - 8; i++) 
	{
		for (int j = 0; j <= M - 8; j++) 
		{
			wCount = CheckWhite(i, j);
			bCount = CheckBlack(i, j);
			
			result = min({ result, wCount, bCount });
		}
	}

	cout << result << "\n";

	return 0;
}