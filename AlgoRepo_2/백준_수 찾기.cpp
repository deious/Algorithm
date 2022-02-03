#include <iostream>
#include <algorithm>

using namespace std;

int board[100000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> board[i];

	sort(board, board + N);
	cin >> M;
	int a;
	for (int i = 0; i < M; i++)
	{
		cin >> a;
		int left = 0, mid = 0, right = N - 1;
		bool flag = false;

		while (left <= right)
		{
			mid = (left + right) / 2;

			if (board[mid] == a)
			{
				cout << "1\n";
				flag = true;
				break;
			}
			else if (board[mid] < a)
				left = mid + 1;
			else
				right = mid - 1;
		}

		if (!flag)
			cout << "0\n";
	}

	return 0;
}