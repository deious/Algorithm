#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int K;
int num[1000001][11];

int DFS(string N, int count)
{
	int n = stoi(N);

	if (count == K)
		return n;

	int &maxNum = num[n][count];
	if (maxNum >= 0)
		return maxNum;

	int len = N.size();
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (!i && N[j] == '0')
				continue;
			swap(N[i], N[j]);
			maxNum = max(maxNum, DFS(N, count + 1));
			swap(N[i], N[j]);
		}
	}

	return maxNum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string N;
	memset(num, -1, sizeof(num));

	cin >> N >> K;
	cout << DFS(N, 0) << "\n";

	return 0;
}