#include <iostream>
#include <vector>

using namespace std;

bool check[40001];

int dp[40001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> v;

	for (int i = 2; i <= N; i++)
	{
		if (!check[i])
		{
			for (int j = i * i; j <= N; j += i)
			{
				check[j] = true;
			}
		}
	}

	for (int i = 2; i <= N; i++)
	{
		if (!check[i])
		{
			v.push_back(i);
		}
	}

	int len = v.size();

	dp[0] = 1;
	for (int i = 0; i < len; i++)
	{
		for (int j = v[i]; j <= N; j++)
		{
			dp[j] += (dp[j - v[i]]) % 123456789;
			dp[j] %= 123456789;
		}
	}

	cout << dp[N] << "\n";

	return 0;
}