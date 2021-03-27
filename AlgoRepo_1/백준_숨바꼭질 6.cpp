#include <iostream>

using namespace std;

int GCD(int x, int y)
{
	if (!y)
		return x;
	else
		return GCD(y, x%y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, S, ans = 0, tempNum = 0, n = 0;
	cin >> N >> S;

	if (N == 1)
	{
		cin >> n;
		tempNum = S - n;
		if (tempNum > 0)
			cout << tempNum << "\n";
		else
			cout << tempNum * -1 << "\n";

		return 0;
	}

	cin >> n;
	tempNum = S - n;
	if (tempNum < 0)
		tempNum *= -1;
	ans = tempNum;

	for (int i = 1; i < N; i++)
	{
		int n1;
		cin >> n;
		n1 = S - n;

		if (n1 < 0)
			n1 *= -1;

		ans = GCD(ans, n1);
	}

	cout << ans << "\n";

	return 0;
}