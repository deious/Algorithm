#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int start = 0, end = 0, sum = 0, len = 100000001;
	int N, S;
	cin >> N >> S;

	vector<int> v(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	while (start <= end)
	{
		if (sum >= S)
		{
			len = min(len, end - start);
			sum -= v[start++];
		}
		else if (end == N)
			break;
		else
			sum += v[end++];
	}

	if (len == 100000001)
		len = 0;

	cout << len << "\n";

	return 0;
}