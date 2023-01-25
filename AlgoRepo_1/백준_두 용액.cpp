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

	sort(v.begin(), v.end());

	int start = 0, end = N - 1, minNum = 2100000000, sumNum = 0, sAnswer, eAnswer;

	while (start < end)
	{
		sumNum = abs(v[start] + v[end]);

		if (sumNum < minNum)
		{
			minNum = sumNum;
			sAnswer = v[start];
			eAnswer = v[end];
		}

		if (v[start] + v[end] == 0)
		{
			cout << sAnswer << " " << eAnswer << "\n";
			return 0;
		}
		else if (v[start] + v[end] > 0)
		{
			end--;
		}
		else
		{
			start++;
		}
	}

	cout << sAnswer << " " << eAnswer << "\n";

	return 0;
}