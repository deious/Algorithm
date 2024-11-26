#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	int ans = 1;
	int temp = K;
	for (int i = N; i > N - K; i--)
	{
		ans *= i;
	}

	for (int i = K; i > 0; i--)
	{
		ans /= i;
	}

	cout << ans << "\n";

	return 0;
}