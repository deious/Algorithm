#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int root[100001];

int FindRoot(int x)
{
	if (root[x] == x)
	{
		return x;
	}
	else
	{
		return root[x] = FindRoot(root[x]);
	}
}

void Union(int x, int y)
{
	x = FindRoot(x);
	y = FindRoot(y);

	if (x != y)
	{
		root[y] = x;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M, a, b, c, answer = 0;
	vector<tuple<int, int, int>> v;

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		v.push_back({ c, a, b });
	}

	for (int i = 1; i <= N; i++)
	{
		root[i] = i;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < M; i++)
	{
		if (FindRoot(get<1>(v[i])) != FindRoot(get<2>(v[i])))
		{
			Union(get<1>(v[i]), get<2>(v[i]));
			answer += get<0>(v[i]);
		}
	}

	cout << answer << "\n";
	
	return 0;
}