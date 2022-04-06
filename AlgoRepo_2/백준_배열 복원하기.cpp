#include <iostream>

using namespace std;

int board[600][600];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int H, W, X, Y;
	cin >> H >> W >> X >> Y;

	for (int i = 0; i < H + X; i++)
		for (int j = 0; j < W + Y; j++)
			cin >> board[i][j];

	for (int i = X; i < H; i++)
		for (int j = Y; j < W; j++)
			board[i][j] -= board[i - X][j - Y];

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}