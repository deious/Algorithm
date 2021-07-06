#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int dp[1001][1001];
int name[1001];

int solution(int index, int len)
{
	if (index > n)
		return 0;

	int& result = dp[index][len];

	if (result != -1)
		return result;

	result = (m - len + 1) * (m - len + 1) + solution(index + 1, name[index] + 1);

	if (len + name[index] <= m)
		result = min(result, solution(index + 1, len + name[index] + 1));

	return result;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> name[i];

	memset(dp, -1, sizeof(dp));
	cout << solution(2, name[1] + 1) << "\n";

	return 0;
}