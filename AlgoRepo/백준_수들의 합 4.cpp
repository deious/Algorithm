#include <iostream>
#include <map>

using namespace std;

int sumNum[200001], arr[200001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	long long answer = 0;

	map<int, long long> m;
	cin >> N >> K;

	int n;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		sumNum[i] = sumNum[i - 1] + arr[i];
		if (sumNum[i] == K)
		{
			answer++;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		answer += m[sumNum[i] - K];
		m[sumNum[i]]++;
	}

	cout << answer << "\n";

	return 0;
}