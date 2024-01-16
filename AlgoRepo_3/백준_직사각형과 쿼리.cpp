#include <iostream>

using namespace std;

int arr[301][301][11];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, Q, x1, y1, x2, y2;
	cin >> N;

	for (int i = 1; i <= N; i++) 
	{
		for (int j = 1; j <= N; j++) 
		{
			int A;
			cin >> A;
			for (int k = 1; k <= 10; k++) 
			{
				arr[i][j][k] = arr[i - 1][j][k] + arr[i][j - 1][k] - arr[i - 1][j - 1][k] + (k == A ? 1 : 0);
			}
		}
	}

	cin >> Q;

	while (Q--) 
	{
		cin >> x1 >> y1 >> x2 >> y2;
		int ans = 0;
		for (int i = 1; i <= 10; i++) 
		{
			int cur = arr[x2][y2][i] - arr[x2][y1 - 1][i] - arr[x1 - 1][y2][i] + arr[x1 - 1][y1 - 1][i];
			if (cur)
			{
				ans++;
			}
		}

		cout << ans << "\n";
	}

	return 0;
}