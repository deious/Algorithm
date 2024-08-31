#include <iostream>
#include <algorithm>

using namespace std;

long long arr[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long N, X;
    int ans = 0;

    cin >> N >> X;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int l = 0, r = N - 1;
    int left = 0;

    while (arr[r] >= X && r >= 0)
    {
        r--;
        ans++;
    }

    while (l <= r)
    {
        if (l < r &&arr[r] + arr[l] >= (X + 1) / 2)
        {
            ans++;
            l++;
            r--;
        }
        else {
            l++;
            left++;
        }
    }
    cout << ans + left / 3;


    return 0;
}