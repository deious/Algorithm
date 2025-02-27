#include <iostream>

using namespace std;

int arr[1001];

bool Calculate(int num)
{
    for (int i = 1; i <= 50; i++)
    {
        for (int j = 1; j <= 50; j++)
        {
            for (int k = 1; k <= 50; k++)
            {
                if (arr[i] + arr[j] + arr[k] == num)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int K, T;
    cin >> T;

    for (int i = 1; i <= 1000; i++)
    {
        arr[i] = arr[i - 1] + i;
    }

    while (T--)
    {
        cin >> K;
        cout << Calculate(K) << "\n";
    }

    return 0;
}