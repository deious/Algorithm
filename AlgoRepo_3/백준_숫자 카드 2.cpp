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
	vector<int> v(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	cin >> M;
	sort(v.begin(), v.end());

	int a;
	for (int i = 0; i < M; i++)
	{
		cin >> a;
		cout << upper_bound(v.begin(), v.end(), a) - lower_bound(v.begin(), v.end(), a) << " ";
	}

	return 0;
}