#include <iostream>

using namespace std;

long long board[1000001];
long long segmentTree[4000004];

int N, M, K;

long long CreateTree(int start, int end, int num)
{
	if (start == end)
		return segmentTree[num] = board[start];

	int mid = (start + end) / 2;
	return segmentTree[num] = CreateTree(start, mid, num * 2) + CreateTree(mid + 1, end, num * 2 + 1);
}

long long Sum(int start, int end, int num, int left, int right)
{
	if (left > end || right < start)
		return 0;

	if (left <= start && end <= right)
		return segmentTree[num];

	int mid = (start + end) / 2;
	return Sum(start, mid, num * 2, left, right) + Sum(mid + 1, end, num * 2 + 1, left, right);
}

void Update(int start, int end, int num, int index, long long value)
{
	if (index < start || end < index)
		return;

	segmentTree[num] += value;
	if (start == end)
		return;

	int mid = (start + end) / 2;
	Update(start, mid, num * 2, index, value);
	Update(mid + 1, end, num * 2 + 1, index, value);

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
		cin >> board[i];

	CreateTree(0, N - 1, 1);
	
	long long a, b, c;
	for (int i = 0; i < M + K; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			long long temp = c - board[b - 1];
			board[b - 1] = c;
			Update(0, N - 1, 1, b - 1, temp);
		}
		else
			cout << Sum(0, N - 1, 1, b - 1, c - 1) << "\n";
	}

	return 0;
}