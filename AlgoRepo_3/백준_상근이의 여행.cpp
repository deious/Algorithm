#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T, N, M;
	cin >> T;

	while (T--)
	{
		cin >> N >> M;
		int a, b;
		for (int i = 0; i < M; i++)
			cin >> a >> b;

		cout << N - 1 << "\n";
	}

	return 0;
}