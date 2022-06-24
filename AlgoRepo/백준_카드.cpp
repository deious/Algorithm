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

	vector<long long> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	long long answer = v[0];
	int numCount = 1;
	int maxCount = 1;

	for (int i = 0; i < N - 1; i++)
	{
		if (v[i] == v[i + 1])
			numCount++;
		else
		{
			if (maxCount < numCount)
			{
				maxCount = numCount;
				answer = v[i];
			}

			numCount = 1;
		}
	}

	if (numCount > maxCount)
		answer = v[N - 1];

	cout << answer << "\n";

	return 0;
}