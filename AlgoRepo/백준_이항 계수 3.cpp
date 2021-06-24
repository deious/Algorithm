#include <iostream>

using namespace std;

long long B = 1, C = 0;

long long solve(int x)
{
	if (x == 0)
		return 1;

	if (x % 2 == 1)
		return B * solve(x - 1) % 1000000007;
	else
	{
		C = solve(x / 2);
		return (C * C) % 1000000007;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long N, K, A = 1;
	cin >> N >> K;

	for (int i = N; i >= N - K + 1; i--)
		A = (A * i) % 1000000007;

	for (int i = 1; i <= K; i++)
		B = (B * i) % 1000000007;

	B = solve(1000000007 - 2);

	cout << (A * B) % 1000000007 << "\n";

	return 0;
}