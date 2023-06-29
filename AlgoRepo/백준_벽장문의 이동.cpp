#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, doorNum;
int order[21];
int dp[21][21][21];

int MoveCheck(int orderIdx, int open1, int open2)
{
	if (orderIdx > doorNum)
		return 0;

	int &result = dp[orderIdx][open1][open2];

	if (result != -1)
		return result;

	result = min(abs(order[orderIdx] - open1) + MoveCheck(orderIdx + 1, order[orderIdx], open2), abs(order[orderIdx] - open2) + MoveCheck(orderIdx + 1, open1, order[orderIdx]));

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	int open1, open2;

	cin >> open1 >> open2 >> doorNum;

	for (int i = 1; i <= doorNum; i++)
		cin >> order[i];

	memset(dp, -1, sizeof(dp));

	cout << MoveCheck(1, open1, open2) << "\n";

	return 0;
}