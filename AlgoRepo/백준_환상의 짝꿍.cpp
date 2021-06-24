#include <iostream>
#include <vector>

using namespace std;

bool num[2000001];

vector<int> v;

bool PrimeCheck(long long x)
{
	if (x <= 2000000)
		return !num[x];
	else
	{
		int len = v.size();
		for (int i = 0; i < len; i++)
		{
			if (x % v[i] == 0)
				return false;
		}

		return true;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	for (int i = 2; i < 2000001; i++)
	{
		if (!num[i])
		{
			v.push_back(i);
			for (int j = i * 2; j < 2000001; j += i)
				num[j] = true;
		}
	}

	long long a, b, sum;
	while (T--)
	{
		cin >> a >> b;
		sum = a + b;
		if (sum <= 3)
			cout << "NO" << "\n";
		else if (!(sum % 2))
			cout << "YES" << "\n";
		else
		{
			sum -= 2;
			if (PrimeCheck(sum))
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
	}

	return 0;
}