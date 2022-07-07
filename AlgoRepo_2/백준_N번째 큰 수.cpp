#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N;

	M = N * N;

	vector<int> v(M);

	for (int i = 0; i < M; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	cout << v[M - N] << "\n";

	return 0;
}