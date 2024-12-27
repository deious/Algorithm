#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, num = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> n;
		num += n * n;
	}

	cout << num % 10 << "\n";

	return 0;
}