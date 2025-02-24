#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    int st = 0, end = 0, cnt = 0, ans = 0;
    while (end < N)
    {
        if (cnt > K)
        {
            if (v[st] % 2 == 1)
            {
                cnt--;
            }
            st++;
        }
        else
        {
            if (v[end] % 2 == 1)
            {
                cnt++;
            }
            end++;
        }

        if (cnt <= K)
        {
            ans = max(ans, end - st - cnt);
        }
    }

    cout << ans << "\n";

    return 0;
}