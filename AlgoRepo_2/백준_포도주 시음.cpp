#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	vector<int> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int start = 0, end = N - 1;
	long long ans = v[end--];
	K--;

	while (K >= 2)
	{
		ans += v[end--] - v[start++];
		K -= 2;
	}

	cout << ans << "\n";

	return 0;
}