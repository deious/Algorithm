#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long K;

vector<long long> A;
vector<long long> B;

bool check(long long mid)
{
    long long cnt = 0;

    for (int i = 0; i < N; i++)
    {
        int s = 0;
        int e = N - 1;

        int idx = 0;

        while (s <= e)
        {
            int temp = (s + e) / 2;

            if (A[i] * B[temp] <= mid)
            {
                idx = temp + 1;
                s = temp + 1;
            }
            else
            {
                e = temp - 1;
            }
        }

        cnt += idx;
    }

    return cnt >= K;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    int temp;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        A.push_back(temp);
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        B.push_back(temp);
    }

    sort(B.begin(), B.end());

    long long s = A[0] * B[0];
    long long e = A[N - 1] * B[N - 1];

    long long ans = 0;
    while (s <= e)
    {
        long long mid = (s + e) / 2;

        if (check(mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}