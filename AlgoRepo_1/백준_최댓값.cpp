#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int maxNum = 0, idx = 0, temp;

	for (int i = 1; i <= 9; i++)
	{
		cin >> temp;
		if (temp > maxNum)
		{
			maxNum = temp;
			idx = i;
		}
	}

	cout << maxNum << "\n" << idx << "\n";

	return 0;
}