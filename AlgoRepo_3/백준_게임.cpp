#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long X, Y;
    cin >> X >> Y;
    long long Z = (100 * Y) / X;

    if (Z >= 99)
    {
        cout << "-1" << "\n";
        return 0;
    }

    long long right = 2100000000;
    long long left = 0;

    while (left <= right)
    {
        long long mid = (left + right) / 2;
        int temp = (100 * (Y + mid)) / (X + mid);

        if (temp > Z)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << left << "\n";

    return 0;
}