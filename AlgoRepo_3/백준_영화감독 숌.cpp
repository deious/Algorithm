#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    int N, cnt = 0;
    cin >> N;

    for (int i = 666;; i++) 
    {
        int temp = i;
        while (temp >= 666) 
        {
            if (temp % 1000 == 666) 
            {
                cnt++;
                break;
            }
            temp /= 10;
        }

        if (N == cnt) 
        {
            cout << i << "\n";
            break;
        }
    }

	return 0;
}