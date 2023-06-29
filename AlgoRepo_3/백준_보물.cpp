#include <iostream>
#include <algorithm>

using namespace std;

int a[50];
int b[50];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == 0)
				cin >> a[j];
			else
				cin >> b[j];
		}
	}

	sort(a, a + N);
	sort(b, b + N, greater<int>());

	int sum = 0;
	for (int i = 0; i < N; i++)
		sum += (a[i] * b[i]);

	cout << sum << "\n";

	return 0;
}