#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];
int dp[1001];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;

        int ans = -210000000;

        for (int i = 1; i <= n; i++) 
        {
            cin >> arr[i];

            dp[i] = max(dp[i - 1] + arr[i], arr[i]);
            ans = max(ans, dp[i]);

        }
        cout << ans << "\n";
    }

    return 0;
}