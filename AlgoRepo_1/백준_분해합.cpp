#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	int ans = 0;

	for (int i = 1; i < N; i++) 
	{
		int sum = 0;
		int num = i;

		while (num) 
		{
			sum += num % 10;
			num /= 10;
		}

		if (sum + i == N) 
		{
			ans = i;
			break;
		}
	}

	cout << ans << "\n";

	return 0;
}