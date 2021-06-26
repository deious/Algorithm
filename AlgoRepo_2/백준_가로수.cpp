#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GCD(int a, int b)
{
	if (!b)
		return a;

	return GCD(b, a % b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> v(N), v1(N - 1);
	
	for (int i = 0; i < N; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	for (int i = 1; i < N; i++)
		v1[i - 1] = v[i] - v[i - 1];

	int gcd = v1[0];
	for (int i = 1; i < N - 1; i++)
		gcd = GCD(gcd, v1[i]);

	int ans = v[N - 1] - v[0];
	ans /= gcd;
	ans -= (N - 1);

	cout << ans << "\n";

	return 0;
}