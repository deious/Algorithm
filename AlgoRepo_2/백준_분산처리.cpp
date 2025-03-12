#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T, a, b;
	cin >> T;

	while (T--)
	{
		cin >> a >> b;

		int num = 1;
		for (int i = 0; i < b; i++)
		{
			num = (num * a) % 10;
		}

		if (num == 0)
		{
			cout << 10 << "\n";
		}
		else
		{
			cout << num << "\n";
		}
	}

	return 0;
}