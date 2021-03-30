#include <iostream>

using namespace std;

bool check[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T, N;
	cin >> T;
	check[0] = check[1] = true;

	for (int i = 2; i * i <= 1000000; i++)
	{
		for (int j = i * i; j <= 1000000; j += i)
		{
			if (!check[j])
				check[j] = true;
		}
	}

	while (T--)
	{
		cin >> N;
		int count = 0;

		for (int i = 2; i < N; i++)
		{
			if (!check[i] && !check[N - i])
			{
				count++;

				if (N - i == i)
					count++;
			}
		}

		cout << count / 2 << "\n";
	}

	return 0;
}