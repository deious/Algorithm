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

	int a;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		v.push_back(a);
	}

	sort(v.rbegin(), v.rend());

	int answer = 0, index = 0;
	while (K != 0)
	{
		int temp = K / v[index];
		if (temp == 0)
		{
			index++;
			continue;
		}

		K -= (temp * v[index]);
		answer += temp;
	}

	cout << answer << "\n";

	return 0;
}