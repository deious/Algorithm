#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1000001][2];
bool check[1000001];
vector<int> node[1000001];

void DFS(int num)
{
	check[num] = true;

	dp[num][0] = 0;
	dp[num][1] = 1;

	for (int i = 0; i < node[num].size(); i++)
	{
		if (check[node[num][i]])
			continue;

		DFS(node[num][i]);
		dp[num][0] += dp[node[num][i]][1];
		dp[num][1] += min(dp[node[num][i]][0], dp[node[num][i]][1]);
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	int a, b;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}

	DFS(1);

	cout << min(dp[1][0], dp[1][1]) << "\n";

	return 0;
}