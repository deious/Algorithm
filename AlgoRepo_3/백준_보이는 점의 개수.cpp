#include <iostream>

using namespace std;

int arr[1001];

int GCD(int a, int b)
{
	int t;
	while (b)
	{
		t = a % b;
		a = b;
		b = t;
	}

	return a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int C;
	cin >> C;
	arr[1] = 3;
	for (int i = 2; i <= 1000; i++)
	{
		int cnt = 0;
		for (int j = 1; j < i; j++)
		{
			if (GCD(i, j) == 1)
			{
				cnt++;
			}
		}

		arr[i] = arr[i - 1] + 2 * cnt;
	}

	int N;
	while (C--)
	{
		cin >> N;
		cout << arr[N] << "\n";
	}

	return 0;
}