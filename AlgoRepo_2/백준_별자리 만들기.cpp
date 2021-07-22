#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

using namespace std;

int parent[101];
int N;

vector<pair<double, double>> star;
vector<tuple<double, int, int>> starDistance;

int Find(int x)
{
	if (parent[x] == x)
		return x;

	return parent[x] = Find(parent[x]);
}

bool Union(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x == y)
		return false;
	else
	{
		parent[x] = y;
		return true;
	}
}

double CalculateDistance(double a, double b, double c, double d)
{
	double x = pow(a - c, 2);
	double y = pow(b - d, 2);

	return sqrt(x + y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
		parent[i] = i;

	star.push_back(make_pair(0, 0));

	double x, y;
	for (int i = 1; i <= N; i++)
	{
		cin >> x >> y;
		star.push_back(make_pair(x, y));
	}

	double z;
	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			z = CalculateDistance(star[i].first, star[i].second, star[j].first, star[j].second);
			starDistance.push_back(make_tuple(z, i, j));
		}
	}

	sort(starDistance.begin(), starDistance.end());

	int len = starDistance.size();
	double ans = 0;
	for (int i = 0; i < len; i++)
	{
		z = get<0>(starDistance[i]);
		x = get<1>(starDistance[i]);
		y = get<2>(starDistance[i]);

		if (Union(x, y))
			ans += z;
	}

	cout << fixed;
	cout.precision(2);
	cout << ans << "\n";

	return 0;
}