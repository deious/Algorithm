#include<iostream>

using namespace std;

long long N, K, A, B, half;
long long mod = 1000000007;

long long Calculate(int x)
{
	if (x == 0)
		return 1;

	if (x % 2 == 1)
		return B * Calculate(x - 1) % mod;
	else
	{
		half = Calculate(x / 2);
		return half * half % mod;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	A = 1;

	for (int i = N; i >= N - K + 1; i--)
		A = (A * i) % mod;

	B = 1;
	for (int i = 1; i <= K; i++)
		B = (B * i) % mod;

	B = Calculate(mod - 2);

	cout << A * B % mod << "\n";

	return 0;
}