#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	int answer = 0;
	for (int i = 1; i <= 500; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (i * i == j * j + N)
			{
				answer++;
			}
		}
	}

	cout << answer << "\n";

	return 0;
}