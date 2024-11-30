#include <iostream>

using namespace std;

int arr[8];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 8; i++)
	{
		cin >> arr[i];
	}

	int cnt = 0;
	for (int i = 0; i < 7; i++)
	{
		if (arr[i] < arr[i + 1])
		{
			cnt++;
		}
		else if (arr[i] > arr[i + 1])
		{
			cnt--;
		}
	}

	if (cnt == 7)
	{
		cout << "ascending\n";
	}
	else if (cnt == -7)
	{
		cout << "descending\n";
	}
	else
	{
		cout << "mixed\n";
	}

	return 0;
}