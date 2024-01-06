#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M, K;
	cin >> N >> M >> K;

	int answer = 0, total = N + M;
	for (int i = M; i >= 0; i--)
	{
		if (i * 2 <= N)
		{
			if (i * 2 + i + K <= total)
			{
				answer = i;
				break;
			}
		}
	}

	cout << answer << "\n";

	return 0;
}