#include <iostream>

using namespace std;

int testTube[100000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> testTube[i];

	int left = 0, mid = 0, right = N - 1;
	int answer = 2100000000;

	while (left < right)
	{
		mid = testTube[left] + testTube[right];

		if (mid == 0)
		{
			cout << "0\n";
			return 0;
		}

		if (abs(mid) < abs(answer))
			answer = mid;

		if (mid > 0)
			right--;
		else
			left++;

	}

	cout << answer << "\n";

	return 0;
}