#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[500][500];
string s;

int FindMax(int start, int end)
{
	if (start >= end)
		return 0;

	int &ans = dp[start][end];
	if (ans != -1)
		return ans;

	ans = 0;
	if ((s[start] == 'a' && s[end] == 't') || (s[start] == 'g' && s[end] == 'c'))
		ans = FindMax(start + 1, end - 1) + 2;

	for (int i = start; i < end; i++)
		ans = max(ans, FindMax(start, i) + FindMax(i + 1, end));

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> s;

	memset(dp, -1, sizeof(dp));
	int len = s.size();

	cout << FindMax(0, len - 1) << "\n";

	return 0;
}