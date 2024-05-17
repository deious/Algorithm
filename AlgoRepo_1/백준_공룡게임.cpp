#include <iostream>

using namespace std;

long long dp[1001][1001][3][3];
int N;

long long Calculate(int cur, int total, bool two, int cnt)
{
    if (cur > N)
    {
        return 0;
    }

    if (cur == N)
    {
        if (two)
        {
            return 1;
        }

        return 0;
    }

    if (dp[cur][total][two][cnt] != -1)
    {
        return dp[cur][total][two][cnt] % 1000000007;
    }

    long long ret = 0;

    if (cnt <= 1)
    {
        if (total + 1 < 4)
        {
            ret += Calculate(cur + 1, total + 1, two, cnt + 1) % 1000000007;
        }

        if (total + 2 < 4)
        {
            ret += Calculate(cur + 1, total + 2, true, cnt + 1) % 1000000007;
        }
    }
    ret += Calculate(cur + 1, 0, two, 0) % 1000000007;

    dp[cur][total][two][cnt] = ret % 1000000007;

    return dp[cur][total][two][cnt];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    fill(&dp[0][0][0][0], &dp[1000][1000][2][3], -1);

    cout << Calculate(1, 0, false, 0) % 1000000007;

    return 0;
}