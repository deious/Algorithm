#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int root[100000];

bool checkCost(vector<int> &a, vector<int> &b)
{
	return a[2] < b[2];
}

int findRoot(int num)
{
	if (num == root[num]) return num;
	else return root[num] = findRoot(root[num]);
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, answer = 0;
	cin >> n >> m;
	vector<vector<int>> v(m, vector<int>(3));

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		root[i] = i;
	}

	sort(v.begin(), v.end(), checkCost);
	
	int endPoint = n - 2;
	int count = 0;
	int index = 0;

	while (count != endPoint)
	{
		int start = findRoot(v[index][0]);
		int end = findRoot(v[index][1]);
		int cost = v[index][2];

		if (start != end)
		{
			root[end] = start;
			answer += cost;
			count++;
		}
		index++;
	}

	cout << answer;

	return 0;
}