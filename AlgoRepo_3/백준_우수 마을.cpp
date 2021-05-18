#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int dp[10001][2];
int population[10001];
bool check[10001];

vector<int> tree[10001];

void dfs(int index) 
{
	check[index] = true;

	dp[index][0] = 0;
	dp[index][1] = population[index];

	int len = tree[index].size();

	for (int i = 0; i < len; i++) 
	{
		int next = tree[index][i];
		if (check[next]) 
			continue;

		dfs(next);

		dp[index][0] += max(dp[next][0], dp[next][1]);
		dp[index][1] += dp[next][0];
	}

	check[index] = false;
	return;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> population[i];

	int x, y;
	for (int i = 1; i < N; i++)
	{
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}

	dfs(1);
	cout << max(dp[1][0], dp[1][1]) << "\n";

	return 0;
}