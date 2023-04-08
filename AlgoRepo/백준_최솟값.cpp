#include <iostream>
#include <algorithm>

using namespace std;

long long board[100001];
long long minTree[400004];

int N, M;

long long CreateTree(int start, int end, int num)
{
	if (start == end)
	{
		return minTree[num] = board[start];
	}

	int mid = (start + end) / 2;

	return minTree[num] = min(CreateTree(start, mid, num * 2), CreateTree(mid + 1, end, num * 2 + 1));
}

long long FindMin(int start, int end, int num, int left, int right)
{
	if (left > end || right < start)
	{
		return 2100000000;
	}

	if (left <= start && end <= right)
	{
		return minTree[num];
	}

	int mid = (start + end) / 2;

	return min(FindMin(start, mid, num * 2, left, right), FindMin(mid + 1, end, num * 2 + 1, left, right));
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

	CreateTree(0, N - 1, 1);

	long long a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		if (a > b)
			cout << FindMin(0, N - 1, 1, b - 1, a - 1) << "\n";
		else
			cout << FindMin(0, N - 1, 1, a - 1, b - 1) << "\n";
	}

	return 0;
}