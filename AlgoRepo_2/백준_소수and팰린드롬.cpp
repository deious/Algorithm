#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool check[10000001];

bool Palindrome(int i)
{
	string s = to_string(i);
	int len = s.size();

	for (int i = 0; i < len / 2; i++)
	{
		if (s[i] != s[len - i - 1])
			return false;
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	check[0] = true;
	check[1] = true;

	for (int i = 2; i <= sqrt(10000000); i++)
	{
		if (check[i])
			continue;

		for (int j = i * i; j <= 10000000; j += i)
			check[j] = true;
	}

	for (int i = N; ; i++)
	{
		if (!check[i])
		{
			if (Palindrome(i))
			{
				cout << i << "\n";
				return 0;
			}
		}
	}

	return 0;
}