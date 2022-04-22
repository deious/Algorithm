#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, newScore, P;
	cin >> N >> newScore >> P;

	int n;
	vector<int> v(P, -1);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	if (v[P - 1] > newScore)
	{
		cout << "-1\n";
		return 0;
	}

	v.push_back(newScore);
	sort(v.begin(), v.end(), greater<int>());

	int sum = 0;
	int answer = 1;
	for (int i = 1; i < P; i++)
	{
		if (v[i] < newScore)
		{
			cout << answer << "\n";
			return 0;
		}

		if (v[i - 1] != v[i])
		{
			answer += sum + 1;
			sum = 0;
		}
		else
			sum++;
	}

	if (v[P] == newScore)
		cout << "-1\n";
	else
		cout << answer << "\n";

	return 0;
}