#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>
#include <algorithm>

using namespace std;

int N, M;
vector<pair<int, int>> graph;
vector<tuple<double, int, int>> v;
int root[1001];

int Find(int x)
{
	if (root[x] == x)
		return x;
	else
		return root[x] = Find(root[x]);
}

bool Union(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x == y)
		return false;
	else
	{
		root[x] = y;
		return true;
	}

}

double CalculateDistance(double a, double b, double c, double d)
{
	return sqrt(pow(a - c, 2) + pow(b - d, 2));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		root[i] = i;

	int x, y;
	graph.push_back(make_pair(0, 0));
	for (int i = 1; i <= N; i++)
	{
		cin >> x >> y;
		graph.push_back(make_pair(x, y));
	}

	for (int i = 0; i < M; i++)
	{
		cin >> x >> y;
		Union(x, y);
	}

	double temp;
	for (int i = 1; i < N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			temp = CalculateDistance(graph[i].first, graph[i].second, graph[j].first, graph[j].second);
			v.push_back(make_tuple(temp, i, j));
		}
	}

	sort(v.begin(), v.end());

	int len = v.size();
	double ans = 0;

	for (int i = 0; i < len; i++)
	{
		temp = get<0>(v[i]);
		x = get<1>(v[i]);
		y = get<2>(v[i]);

		if (Union(x, y))
			ans += temp;
	}

	cout << fixed;
	cout.precision(2);
	cout << ans << "\n";

	return 0;
}