#include <iostream>
#include <algorithm>

using namespace std;

int board[100000][3];
int maxDp[2][3];
int minDp[2][3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, maxAns = 0, minAns = 210000000;
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			cin >> board[i][j];

	for (int i = 0; i < 3; i++)
		maxDp[0][i] = minDp[0][i] = board[0][i];

	for (int i = 1; i < N; i++)
	{
		maxDp[1][0] = max(maxDp[0][0], maxDp[0][1]) + board[i][0];
		maxDp[1][1] = max({ maxDp[0][0], maxDp[0][1], maxDp[0][2] }) + board[i][1];
		maxDp[1][2] = max(maxDp[0][1], maxDp[0][2]) + board[i][2];

		minDp[1][0] = min(minDp[0][0], minDp[0][1]) + board[i][0];
		minDp[1][1] = min({ minDp[0][0], minDp[0][1], minDp[0][2] }) + board[i][1];
		minDp[1][2] = min(minDp[0][1], minDp[0][2]) + board[i][2];

		for (int j = 0; j < 3; j++)
		{
			maxDp[0][j] = maxDp[1][j];
			minDp[0][j] = minDp[1][j];
		}
	}
	maxAns = max({ maxDp[0][0], maxDp[0][1], maxDp[0][2] });
	minAns = min({ minDp[0][0], minDp[0][1], minDp[0][2] });

	cout << maxAns << " " << minAns << "\n";

	return 0;
}