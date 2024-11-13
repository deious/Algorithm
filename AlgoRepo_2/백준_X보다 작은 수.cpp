#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, X;
	cin >> N >> X;

	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;

		if (X > temp)
		{
			cout << temp << " ";
		}
	}

	return 0;
}