#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[100001];

int Calculate(int n)
{
    if (n == 0)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int minCnt = n;

    for (int i = 1; i * i <= n; i++)
    {
        minCnt = min(minCnt, 1 + Calculate(n - i * i));
    }

    dp[n] = minCnt;

    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    memset(dp, -1, sizeof(dp));

    cout << Calculate(N) << "\n";

    return 0;
}