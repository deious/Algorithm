#include <iostream>
#include <vector>

using namespace std;

bool check[1000000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 2; i <= 1000000; i++)
	{
		if (check[i])
		{
			continue;
		}

		for (int j = i + i; j <= i; j += i)
		{
			check[j] = true;
		}
	}

	int N;
	cin >> N;

	vector<int> v;
	for (int i = 2; i <= 1000000; i++)
	{
		if (!check[i])
		{
			v.push_back(i);
		}
	}

	long long num;
	int len = v.size();
	for (int i = 0; i < N; i++)
	{
		bool checkNum = false;
		cin >> num;
		for (int j = 0; j < len; j++)
		{
			if (num % v[j] == 0)
			{
				cout << "NO\n";
				checkNum = true;
				break;
			}
		}

		if (!checkNum)
		{
			cout << "YES\n";
		}
	}

	return 0;
}