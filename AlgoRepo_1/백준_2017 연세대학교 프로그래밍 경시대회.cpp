#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= N; k++)
			{
				if (i % 2 == 0 && k > j + 1 && i + j + k == N)
				{
					answer++;
				}
			}
		}
	}

	cout << answer << "\n";

	return 0;
}