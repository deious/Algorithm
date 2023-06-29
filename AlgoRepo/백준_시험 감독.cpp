#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, B, C;
	long ans = 0;
	cin >> N;
	vector<int> v(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	cin >> B >> C;
	long num;

	for (int i = 0; i < N; i++)
	{
		num = v[i] - B;
		ans++;
		if (num > 0)
		{
			if (num % C == 0)
				ans += (num / C);
			else
				ans += (num / C) + 1;
		}
	}

	cout << ans << "\n";

	return 0;
}