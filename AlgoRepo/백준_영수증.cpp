#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, X;
	cin >> X >> N;

	int a, b, ans = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		ans += (a * b);
	}

	if (ans == X)
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "No\n";
	}

	return 0;
}