#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info
{
	int num, color, size;
};

bool operator<(info const a, info const b)
{
	if (a.size == b.size) 
		return a.color < b.color;

	return a.size > b.size;
}

info ball[200001];
int sizeCount[2001];
int colorSum[200001];
int ans[200001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	int x, y;
	for (int i = 1; i <= N; i++)
	{
		cin >> ball[i].color >> ball[i].size;
		ball[i].num = i;
		sizeCount[ball[i].size]++;
	}

	sort(ball + 1, ball + N + 1);
		
	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		colorSum[ball[i].color] += ball[i].size;
		sum += ball[i].size;
	}

	for (int i = 1; i <= N; i++)
	{
		int a = lower_bound(ball + i, ball + N + 1, ball[i]) - ball;
		int b = upper_bound(ball + i, ball + N + 1, ball[i]) - ball;

		ans[ball[i].num] = sum - colorSum[ball[i].color] - (sizeCount[ball[i].size] - (b - a)) * ball[i].size;
		sum -= ball[i].size;
		colorSum[ball[i].color] -= ball[i].size;
		sizeCount[ball[i].size]--;
	}

	for (int i = 1; i <= N; i++)
		cout << ans[i] << "\n";

	return 0;
}