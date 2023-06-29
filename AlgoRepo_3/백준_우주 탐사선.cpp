#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N, K, ans = INT_MAX;

int planet[10][10];
bool check[10];

void DFS(int curPlanet, int distance, int count)
{
	if (distance > ans)
		return;
	if (count == N)
	{
		ans = min(ans, distance);
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (check[i])
			continue;
		check[i] = true;
		DFS(i, distance + planet[curPlanet][i], count + 1);
		check[i] = false;
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> planet[i][j];

	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (planet[i][k] + planet[k][j] < planet[i][j])
					planet[i][j] = planet[i][k] + planet[k][j];

	check[K] = true;
	DFS(K, 0, 1);
	cout << ans << "\n";

	return 0;
}