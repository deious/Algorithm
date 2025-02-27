#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool prime[4000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int A, B, D, sqrtNum, ans = 0;
	string s, str;

	cin >> A >> B >> D;
	s = to_string(D);
	sqrtNum = sqrt(B);
	prime[0] = prime[1] = true;

	for (int i = 2; i <= sqrtNum; i++)
	{
		if (prime[i])
		{
			continue;
		}

		for (int j = i * i; j <= B; j += i)
		{
			prime[j] = true;
		}
	}

	for (int i = A; i <= B; i++)
	{
		if (!prime[i])
		{
			str = to_string(i);
			if (str.find(s, 0) != string::npos)
			{
				ans++;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}