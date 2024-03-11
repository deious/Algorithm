#include <iostream>

using namespace std;

int egg[8][2];

int N, ans = 0;

void DFS(int num)
{
	if (num >= N)
	{
		int breakEgg = 0;
		for (int i = 0; i < N; i++)
		{
			if (egg[i][0] <= 0)
			{
				breakEgg++;
			}
		}

		if (breakEgg > ans)
		{
			ans = breakEgg;
		}

		return;
	}

	if (egg[num][0] <= 0)
	{
		DFS(num + 1);
	}
	else
	{
		bool check = false;

		for (int i = 0; i < N; i++)
		{
			if (i == num || egg[i][0] <= 0)
			{
				continue;
			}

			egg[num][0] -= egg[i][1];
			egg[i][0] -= egg[num][1];
			check = true;
			DFS(num + 1);
			egg[num][0] += egg[i][1];
			egg[i][0] += egg[num][1];
		}

		if (!check)
		{
			DFS(N);
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> egg[i][0] >> egg[i][1];
	}

	DFS(0);

	cout << ans << "\n";

	return 0;
}