#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;

	int check = 0;
	for (int i = 1; i <= 1000000; i++)
	{
		check = 0;
		if (i % a == 0)
		{
			check++;
		}

		if (i % b == 0)
		{
			check++;
		}

		if (i % c == 0)
		{
			check++;
		}

		if (i % d == 0)
		{
			check++;
		}

		if (i % e == 0)
		{
			check++;
		}

		if (check >= 3)
		{
			cout << i << "\n";
			return 0;
		}
	}

	return 0;
}