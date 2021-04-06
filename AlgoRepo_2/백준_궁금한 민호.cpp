#include <iostream>

using namespace std;

int road[20][20];
int N;
bool checkRoad[20][20];
bool check;

void floyd()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (i == j || i == k || j == k)
					continue;
				else if (road[j][k] > road[j][i] + road[i][k])
				{
					check = true;
					return;
				}
				else if (road[j][k] == road[j][i] + road[i][k])
					checkRoad[j][k] = true;

			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> road[i][j];

	floyd();
	
	if (check)
	{
		cout << "-1\n";
		return 0;
	}

	int ans = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!checkRoad[i][j])
				ans += road[i][j];

	cout << ans / 2 << "\n";

	return 0;
}