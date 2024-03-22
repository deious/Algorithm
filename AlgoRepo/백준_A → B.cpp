#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int A, B, ans = 0;
	cin >> A >> B;

	while (A != B)
	{
		if (A > B)
		{
			cout << "-1\n";
			return 0;
		}

		if (B % 2 == 0)
		{
			B /= 2;
		}
		else if (B % 10 == 1)
		{
			B /= 10;
		}
		else
		{
			cout << "-1\n";
			return 0;
		}

		ans++;
	}

	cout << ans + 1 << "\n";

	return 0;
}