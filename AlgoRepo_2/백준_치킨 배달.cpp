#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int town[50][50];
bool check[13];

vector<pair<int, int>> home, cStore;

int N, M, ans = 210000000;

int CalculateDistance(pair<int, int> x, pair<int, int> y)
{
	int a, b;

	if (x.first - y.first >= 0)
		a = x.first - y.first;
	else
		a = y.first - x.first;

	if (x.second - y.second >= 0)
		b = x.second - y.second;
	else
		b = y.second - x.second;

	return a + b;
}

void DFS(int index, int count)
{
	if (count == M)
	{
		int temp = 0;

		for (int i = 0; i < home.size(); i++)
		{
			int dist = 210000000;

			for (int j = 0; j < cStore.size(); j++)
			{
				if (check[j])
					dist = min(dist, CalculateDistance(home[i], cStore[j]));
			}

			temp += dist;
		}

		ans = min(ans, temp);
		return;
	}
	
	if (index == cStore.size())
		return;

	check[index] = true;
	DFS(index + 1, count + 1);
	check[index] = false;
	DFS(index + 1, count);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> town[i][j];
			if (town[i][j] == 1)
				home.push_back(make_pair(i, j));
			else if (town[i][j] == 2)
				cStore.push_back(make_pair(i, j));
		}
	}

	DFS(0, 0);
	cout << ans << "\n";

	return 0;
}