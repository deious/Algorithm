#include <iostream>

using namespace std;

bool check[10];
int sourTaste[10];
int bitter[10];
int ans = 1000000000;
int N;

void Calculate(int n)
{
	int s = 1, b = 0;
	bool flag = false;
	for (int i = 0; i < N; i++)
	{
		if (check[i])
		{
			flag = true;
			s *= sourTaste[i];
			b += bitter[i];
		}
	}

	if (flag)
	{
		ans = min(ans, abs(s - b));
	}

	for (int i = n; i < N; i++)
	{
		if (!check[i])
		{
			check[i] = true;
			Calculate(i);
			check[i] = false;
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	int S, B;
	for (int i = 0; i < N; i++)
	{
		cin >> S >> B;
		sourTaste[i] = S;
		bitter[i] = B;
	}

	Calculate(0);

	cout << ans << "\n";

	return 0;
}