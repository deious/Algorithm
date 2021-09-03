#include <iostream>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

int N;
string S;

int minDp[20][20];	// 범위를 10, 10으로 하면 OutOfBounds가 나옴
int maxDp[20][20];

int calculate(int a, int b, char ope)
{
	if (ope == '+')
		return a + b;
	else if (ope == '-')
		return a - b;
	else
		return a * b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> S;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			minDp[i][j] = INT_MAX;
			maxDp[i][j] = INT_MIN;
		}
	}

	int numCount = N / 2 + 1;

	for (int i = 0; i < numCount; i++)
		minDp[i][i] = maxDp[i][i] = S[i * 2] - '0';

	for (int i = 1; i < numCount; i++)
	{
		for (int j = 0; j < numCount - i; j++)
		{
			for (int k = 1, l = i; k <= i; k++, l--)
			{
				int operatorIndex = (i + j - l) * 2 + 1;
				char ope = S[operatorIndex];

				int minmaxArr[4] = {
					calculate(minDp[j][i + j - l], maxDp[j + k][j + i], ope),
					calculate(minDp[j][i + j - l], minDp[j + k][j + i], ope),
					calculate(maxDp[j][i + j - l], minDp[j + k][j + i], ope),
					calculate(maxDp[j][i + j - l], maxDp[j + k][j + i], ope)
				};

				sort(minmaxArr, minmaxArr + 4);

				minDp[j][i + j] = min(minDp[j][i + j], minmaxArr[0]);
				maxDp[j][i + j] = max(maxDp[j][i + j], minmaxArr[3]);
			}
		}
	}

	cout << maxDp[0][numCount - 1] << "\n";

	return 0;
}