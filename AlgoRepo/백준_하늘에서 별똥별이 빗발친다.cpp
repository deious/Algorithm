#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, L, K;

vector<int> starX;
vector<int> starY;
vector<pair<int, int>> star;

int CountStar(int x, int y)
{
	int starCnt = 0;
	for (int i = 0; i < K; i++)
	{
		int starX = star[i].first;
		int starY = star[i].second;

		if (starX >= x && starX <= x + L && starY >= y && starY <= y + L)
		{
			starCnt++;
		}
	}

	return starCnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> L >> K;

	int x, y;
	for (int i = 0; i < K; i++)
	{
		cin >> x >> y;
		star.push_back({ x, y });
		starX.push_back(x);
		starY.push_back(y);
	}

	int ans = 0;
	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < K; j++)
		{
			ans = max(ans, CountStar(starX[i], starY[j]));
		}
	}

	cout << K - ans << "\n";

	return 0;
}