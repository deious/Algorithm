#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	vector<vector<int>> v(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &v[i][j]);
		}
	}

	int ans = 2100000000;

	for (int k = 1; k < n - 1; k++)
	{

		vector<int> v1(n, 0);

		for (int i = 0; i < k; i++)
			v1[i] = 0;
		for (int i = k; i < n; i++)
			v1[i] = 1;

		do
		{
			vector<int> team1, team2;

			for (int i = 0; i < n; i++)
			{
				if (v1[i] == 0)
					team1.push_back(i);
				else
					team2.push_back(i);
			}

			int a = 0, b = 0;

			for (int i = 0; i < team1.size() - 1; i++)
				for (int j = i + 1; j < team1.size(); j++)
					a += (v[team1[i]][team1[j]] + v[team1[j]][team1[i]]);
			for (int i = 0; i < team2.size() - 1; i++)
				for (int j = i + 1; j < team2.size(); j++)
					b += (v[team2[i]][team2[j]] + v[team2[j]][team2[i]]);

			int temp = a - b;
			if (temp < 0) temp = -temp;
			if (ans > temp) ans = temp;
		} while (next_permutation(v1.begin(), v1.end()));
	}

	printf("%d", ans);

	return 0;
}