#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int sum = 0;
	vector<int> v(9);

	for (int i = 0; i < 9; i++)
	{
		cin >> v[i];
		sum += v[i];
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if ((sum - v[i] - v[j]) == 100)
			{
				if (i > j) 
				{
					v.erase(v.begin() + i);
					v.erase(v.begin() + j);
				}
				else 
				{
					v.erase(v.begin() + j);
					v.erase(v.begin() + i);
				}

				for (int k = 0; k < 7; k++)
				{
					cout << v[k] << "\n";
				}

				return 0;
			}
		}
	}

	return 0;
}