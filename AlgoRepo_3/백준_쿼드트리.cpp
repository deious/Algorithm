#include <iostream>
#include <string>

using namespace std;

string board[64];

void Check(int x, int y, int len)
{
	char temp = board[x][y];
	bool check = false;
	for (int i = x; i < x + len; i++)
	{
		for (int j = y; j < y + len; j++)
		{
			if (board[i][j] != temp)
			{
				check = true;
				break;
			}
		}
		if (check)
			break;
	}

	if (!check)
	{
		cout <<  temp;
		return;
	}

	cout << "(";
	Check(x, y, len / 2);
	Check(x, y + len / 2, len / 2);
	Check(x + len / 2, y, len / 2);
	Check(x + len / 2, y + len / 2, len / 2);
	cout << ")";

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> board[i];

	Check(0, 0, N);

	return 0;
}