#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[2000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, num;
	cin >> N;

	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	reverse(v.begin(), v.end());

	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;
	}

	for (int i = 1; i < N; i++) 
	{
		for (int j = 0; j < i; j++) 
		{
			if (v[j] < v[i]) 
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int maxValue = 0;

	for (int i = 0; i < N; i++) 
	{
		maxValue = max(maxValue, dp[i]);
	}

	cout << N - maxValue << "\n";

	return 0;
}