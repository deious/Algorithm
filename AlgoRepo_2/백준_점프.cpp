#include <iostream>
#include <algorithm>

using namespace std;

int dp[10001];
bool check[10001];

int N, M;

void Calculate(int start, int jump, int cnt)
{
	if (start > N || start < 1 || check[start])
		return;

	if (dp[start] > cnt)
		dp[start] = cnt;
	else
		return;

	if (start == N)
		dp[N] = min(dp[N], cnt);

	if (start == 1)
		Calculate(start + jump, jump, cnt + 1);
	else if (start > 0 && start < N)
	{
		Calculate(start + jump - 1, jump - 1, cnt + 1);
		Calculate(start + jump, jump, cnt + 1);
		Calculate(start + jump + 1, jump + 1, cnt + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		dp[i] = 2100000000;

	int a;
	for (int i = 0; i < M; i++)
	{
		cin >> a;
		check[a] = true;
	}

	Calculate(1, 1, 0);

	if (dp[N] == 2100000000)
		cout << "-1\n";
	else
		cout << dp[N] << "\n";

	return 0;
}