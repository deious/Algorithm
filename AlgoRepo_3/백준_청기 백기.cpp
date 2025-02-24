#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	int cnt = 0;

	for (long long i = 1; i * i <= N; i++)
	{
		cnt++;
	}

	cout << cnt << "\n";
	return 0;
}