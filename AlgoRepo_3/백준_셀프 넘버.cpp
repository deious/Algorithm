#include <iostream>

using namespace std;

bool check[10001];

int Calculate(int n)
{
	int temp = n;

	while (n)
	{
		temp += n % 10;
		n /= 10;
	}

	return temp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 1; i <= 10000; i++)
	{
		int temp = Calculate(i);

		if (temp <= 10000)
		{
			check[temp] = true;
		}
	}

	for (int i = 1; i <= 10000; i++)
	{
		if (!check[i])
		{
			cout << i << "\n";
		}
	}

	return 0;
}