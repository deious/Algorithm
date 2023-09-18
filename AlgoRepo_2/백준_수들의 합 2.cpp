#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int N, M, answer = 0;
	cin >> N >> M;

	vector<int> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < N; i++)
	{
		int num = 0;
		for (int j = i; j < N; j++)
		{
			num += v[j];
			if (num == M)
			{
				answer++;
				break;
			}
			else if (num > M)
			{
				break;
			}
		}
	}

	cout << answer << "\n";

	return 0;
}