#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> v(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	if (v[0] != 1)
	{
		cout << "1\n";
		return 0;
	}

	int sum = 1;
	for (int i = 1; i < N; i++)
	{
		if (v[i] > sum + 1)
			break;
		sum += v[i];
	}

	cout << sum + 1 << "\n";

	return 0;
}