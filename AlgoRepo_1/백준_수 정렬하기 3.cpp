#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int board[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	
	int a;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		board[a]++;
	}

	for (int i = 1; i < 10001; i++)
	{
		if (board[i])
		{
			for (int j = 0; j < board[i]; j++)
				cout << i << "\n";
		}
	}

	return 0;
}