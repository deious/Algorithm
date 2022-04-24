#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, L;
	cin >> N >> L;

	vector<int> v(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	sort(v.begin(), v.end());
	int start = v[0], answer = 1;

	for (int i = 1; i < N; i++)
	{
		if (v[i] - start + 1 > L)
		{
			answer++;
			start = v[i];
		}
	}

	cout << answer << "\n";

	return 0;
}