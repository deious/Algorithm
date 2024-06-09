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
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	int start = 0, end = N - 1, answer = 0;
	while (start <= end)
	{
		int temp = end - start - 1;
		answer = max(answer, temp * min(v[end], v[start]));

		if (v[start] < v[end])
		{
			start++;
		}
		else
		{
			end--;
		}
	}

	cout << answer << "\n";

	return 0;
}