#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;

int Dist(pair<int, int> a, pair<int, int> b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, sx, sy;
	cin >> N >> sx >> sy;

	int answer = 0;
	v.push_back({ sx,sy });

	int x, y;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> x >> y;
		v.push_back({ x,y });
		answer += Dist({ sx,sy }, { x,y });
		sx = x;
		sy = y;
	}

	pair<int, int> start, middle, end;
	int skip = 0, distance, jump;

	for (int i = 1; i < N - 1; i++)
	{
		start = v[i - 1];
		middle = v[i];
		end = v[i + 1];
		distance = Dist(start, middle) + Dist(middle, end);
		jump = Dist(start, end);
		skip = max(skip, distance - jump);
	}

	cout << answer - skip << "\n";

	return 0;
}