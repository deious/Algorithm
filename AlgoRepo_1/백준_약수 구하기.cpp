#include <iostream>

using namespace std;

int arr[10000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    int cnt = 0;
    int idx = 0;
    for (int i = 1; i <= N; i++)
    {
        if (N % i == 0)
        {
            arr[idx] = i;
            idx++;
            cnt++;
        }
    }

    if (cnt >= K)
    {
        cout << arr[K - 1] << "\n";
    }
    else
    {
        cout << "0\n";
    }

    return 0;
}