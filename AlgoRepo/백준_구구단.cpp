#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= 9; i++)
	{
		cout << N << " * " << i << " = " << N * i << "\n";
	}

	return 0;
}