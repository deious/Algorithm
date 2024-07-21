#include <iostream>

using namespace std;

long long fibo[10001];

long long Fibo(int p, int q)
{
	for (int i = 3; i <= p; i++)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		fibo[i] %= q;
	}

	return fibo[p] % q;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T, P, Q;
	cin >> T;

	fibo[1] = 1, fibo[2] = 1;

	for (int i = 1; i <= T; i++)
	{
		cin >> P >> Q;
		cout << "Case #" << i << ": " << Fibo(P, Q) << "\n";
	}

	return 0;
}