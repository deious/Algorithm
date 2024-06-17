#include <iostream>

using namespace std;

int dp[1001][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T, n, m;
	cin >> T;

    dp[1][1] = dp[2][1] = dp[3][1] = 1;
    for (int i = 2; i <= 1000; i++) 
    {
        for (int j = 1; j <= 1000; j++) 
        {
            for (int k = 1; k < 4; k++) 
            {
                if (j - k > 0)
                {
                    dp[j][i] += dp[j - k][i - 1];
                }

                dp[j][i] %= 1000000009;
            }
        }
    }

    while (T--)
    {
        cin >> n >> m;
        cout << dp[n][m] << "\n";
    }

    return 0;
}