#include <iostream>
#include <algorithm>

using namespace std;

int N, M, K;
int graph[301][301];
int dp[301][301];

int DFS(int index, int cnt)
{
	if (cnt > M)
		return -210000000;

	if (index == N)
		return 0;

	if (dp[index][cnt])
		return dp[index][cnt];

	dp[index][cnt] = -21000000;
	
	for (int i = index + 1; i <= N; i++)
	{
		if (graph[index][i])
			dp[index][cnt] = max(dp[index][cnt], graph[index][i] + DFS(i, cnt + 1));
	}

	return dp[index][cnt];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;

	int a, b, c;
	for (int i = 0; i < K; i++)
	{
		cin >> a >> b >> c;

		if (c > graph[a][b])
			graph[a][b] = c;
	}

	cout << DFS(1, 1) << "\n";

	return 0;
}