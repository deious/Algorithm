#include <iostream>
#include <cstdlib>

using namespace std;

int arr[100];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int tempAns = 210000000, ans = 0;
	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		for (int j = i + 1; j < N; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				temp = arr[i] + arr[j] + arr[k];
				if (M - temp >= 0 && (M - temp < tempAns))
				{
					tempAns = abs(M - temp);
					ans = temp;
				}
			}
		}
	}

	cout << ans << "\n";

	return 0;
}