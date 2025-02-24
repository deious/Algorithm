#include <iostream>
#include <algorithm>

using namespace std;

int charge[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	charge[1] = -1;
	charge[2] = 1;
	charge[3] = -1;
	charge[4] = 2;
	charge[5] = 1;

	for (int i = 6; i <= n; i++)
	{
		if (charge[i - 2] != -1)
		{
			charge[i] = charge[i - 2] + 1;
		}

		if (charge[i - 5] != -1)
		{
			charge[i] = min(charge[i], charge[i - 5] + 1);
		}
	}

	cout << charge[n] << "\n";

	return 0;
}