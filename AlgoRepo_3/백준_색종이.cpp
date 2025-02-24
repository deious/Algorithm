#include <iostream>

using namespace std;

bool board[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	int a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		for (int j = a; j < a + 10; j++)
		{
			for (int k = b; k < b + 10; k++)
			{
				board[j][k] = true;
			}
		}
	}

	int answer = 0;
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			if (board[i][j])
			{
				answer++;
			}
		}
	}

	cout << answer << "\n";

	return 0;
}