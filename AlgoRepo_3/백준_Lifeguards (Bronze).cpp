#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

pair<int, int> arr[100];
int time[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	int a, b, answer = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		arr[i] = { a, b };
	}

	for (int i = 0; i < N; i++)
	{
		memset(time, 0, sizeof(time));

		for (int j = 0; j < N; j++)
		{
			if (i == j)
			{
				continue;
			}

			for (int k = arr[j].first; k < arr[j].second; k++)
			{
				time[k] = 1;
			}
		}

		int temp = 0;
		for (int j = 0; j <= 1000; j++)
		{
			if (time[j] > 0)
			{
				temp++;
			}
		}
		answer = max(temp, answer);
	}

	cout << answer << "\n";

	return 0;
}