#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int M, N;
	cin >> M >> N;

	vector<int> board(M * 2 - 1, 1);

	int zero, one, two;
	while (N--)
	{
		cin >> zero >> one >> two;
		for (int i = zero; i < zero + one; i++)
			board[i]++;

		for (int i = zero + one; i < M * 2 - 1; i++)
			board[i] += 2;
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (j == 0)
				cout << board[M - i - 1] << " ";
			else
				cout << board[M + j - 1] << " ";
		}
		cout << "\n";
	}

	return 0;
}