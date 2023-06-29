#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool check[5][5];

vector<vector<int>> tempBoard;

int row, col;

bool InRange(int x, int y)
{
	return x >= 0 && x < row && y >= 0 && y < col;
}

int Move(int a, int b, int c, int d)
{
	if (check[a][b])
		return 0;

	int playerMoveCount = 0;

	for (int i = 0; i < 4; i++)
	{
		int nx = a + dx[i];
		int ny = b + dy[i];

		if (InRange(nx, ny) && !check[nx][ny] && tempBoard[nx][ny] == 1)
		{
			check[a][b] = true;
			int anotherMoveCount = Move(c, d, nx, ny) + 1;
			check[a][b] = false;

			if (playerMoveCount % 2 == 0 && anotherMoveCount % 2 == 1)
				playerMoveCount = anotherMoveCount;
			else if (playerMoveCount % 2 == 0 && anotherMoveCount % 2 == 0)
				playerMoveCount = max(playerMoveCount, anotherMoveCount);
			else if (playerMoveCount % 2 == 1 && anotherMoveCount % 2 == 1)
				playerMoveCount = min(playerMoveCount, anotherMoveCount);
		}
	}

	return playerMoveCount;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
	tempBoard = board;
	row = board.size();
	col = board[0].size();

	return Move(aloc[0], aloc[1], bloc[0], bloc[1]);
}