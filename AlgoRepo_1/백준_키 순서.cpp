#include <iostream>

using namespace std;

bool check[501][501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		check[i][i] = true;
	}

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		check[a][b] = true;
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (check[i][k] && check[k][j])
				{
					check[i][j] = true;
				}
			}
		}
	}

	bool flag;
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		flag = false;
		for (int j = 1; j <= N; j++) {
			if (!check[i][j] && !check[j][i])
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			answer++;
		}
	}

	cout << answer << "\n";

	return 0;
}