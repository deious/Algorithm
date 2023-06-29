#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp[51][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M, H;
	cin >> N >> M >> H;
	cin.ignore();

	vector<int> v[51];

	for (int i = 1; i <= N; i++) 
	{
		string s;
		getline(cin, s, '\n');
		int len = s.size();

		for (int j = 0; j < len; j++)
		{
			if (s[j] == ' ' || j == 0)
			{
				v[i].push_back(stoi(&s[j]));
			}
		}

	}

	for (int i = 0; i <= N; i++)
		dp[i][0] = 1;

	for (int i = 1; i <= N; i++) 
	{
		for (int j = 1; j <= H; j++) 
		{
			for (int k = 0; k < v[i].size(); k++) 
			{
				if (j >= v[i][k]) 
				{
					dp[i][j] += dp[i - 1][j - v[i][k]];
					dp[i][j] %= 10007;
				}
			}
			dp[i][j] += dp[i - 1][j];
			dp[i][j] %= 10007;
		}
	}


	cout << dp[N][H] << "\n";

	return 0;
}