#include <iostream>

using namespace std;

int dp[41];
int cnt = 0, cnt2 = 0;

int Fibo(int n)
{
    if (n == 1 || n == 2)
    {
        cnt++;
        return 1;
    }
    else
    {
        return (Fibo(n - 1) + Fibo(n - 2));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    Fibo(n);

    dp[1] = dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        cnt2++;
    }
    cout << cnt << " " << cnt2 << "\n";

    return 0;
}