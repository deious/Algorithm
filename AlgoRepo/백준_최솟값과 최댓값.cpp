#include <iostream>
#include <algorithm>

using namespace std;

long long board[100001];
long long maxTree[400004];
long long minTree[400004];

int N, M;

long long CreateTree(int start, int end, int num, bool check)
{
	if (start == end)
	{
		if (check)
			return maxTree[num] = board[start];
		else
			return minTree[num] = board[start];
	}

	int mid = (start + end) / 2;

	if (check)
		return maxTree[num] = max(CreateTree(start, mid, num * 2, check), CreateTree(mid + 1, end, num * 2 + 1, check));
	else
		return minTree[num] = min(CreateTree(start, mid, num * 2, check), CreateTree(mid + 1, end, num * 2 + 1, check));
}

long long FindMinMax(int start, int end, int num, int left, int right, bool check)
{
	if (left > end || right < start)
	{
		if (check)
			return -1000000001;
		else
			return 1000000001;
	}

	if (left <= start && end <= right)
	{
		if (check)
			return maxTree[num];
		else
			return minTree[num];
	}

	int mid = (start + end) / 2;
	if (check)
		return max(FindMinMax(start, mid, num * 2, left, right, check), FindMinMax(mid + 1, end, num * 2 + 1, left, right, check));
	else
		return min(FindMinMax(start, mid, num * 2, left, right, check), FindMinMax(mid + 1, end, num * 2 + 1, left, right, check));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < 400004; i++)
		minTree[i] = 1000000001;

	for (int i = 0; i < N; i++)
		cin >> board[i];

	CreateTree(0, N - 1, 1, true);
	CreateTree(0, N - 1, 1, false);

	long long a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		if (a > b)
			cout << FindMinMax(0, N - 1, 1, b - 1, a - 1, false) << " " << FindMinMax(0, N - 1, 1, b - 1, a - 1, true) << "\n";
		else
			cout << FindMinMax(0, N - 1, 1, a - 1, b - 1, false) << " " << FindMinMax(0, N - 1, 1, a - 1, b - 1, true) << "\n";
	}

	return 0;
}