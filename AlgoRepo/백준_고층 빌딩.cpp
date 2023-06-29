#include <iostream>
#include <cstring>

using namespace std;

long dp[101][101][101];

long CheckBuildings(int N, int L, int R)
{
	if ((L == 1 && R == N) || (R == 1 && L == N))
		return 1;

	if (!N || !L || !R)
		return 0;

	long &ans = dp[N][L][R];

	if (ans != -1)
		return ans;

	ans = 0;
	ans = (CheckBuildings(N - 1, L, R) * (N - 2) + CheckBuildings(N - 1, L - 1, R) + CheckBuildings(N - 1, L, R - 1)) % 1000000007;

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, L, R;
	cin >> N >> L >> R;

	memset(dp, -1, sizeof(dp));

	cout << CheckBuildings(N, L, R) << "\n";

	return 0;
}