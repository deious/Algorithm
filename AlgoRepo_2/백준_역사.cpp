#include <iostream>

using namespace std;

int history[401][401];

int n, k;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	int a, b;

	for (int i = 0; i < k; i++)
	{
		cin >> a >> b;
		history[a][b] = -1;
		history[b][a] = 1;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (history[i][k] == 1 && history[k][j] == 1)
				{
					history[i][j] = 1;
					history[j][i] = -1;
				}
			}
		}
	}

	int s;
	cin >> s;

	for (int i = 0; i < s; i++)
	{
		cin >> a >> b;
		cout << history[a][b] << "\n";
	}

	return 0;
}