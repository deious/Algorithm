#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> v(N);
	int a;

	for (int i = 0; i < N; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	int answer = 0;
	for (int i = 0; i < N; i++)
		answer += v[i] * (N - i);

	cout << answer << "\n";

	return 0;
}