#include <iostream>

using namespace std;

int board[100000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> board[i];

	int left = 0, right = N - 1;
	int leftAnswer, rightAnswer, answer = 2100000000;

	while (left < right)
	{
		int lTemp = board[left];
		int rTemp = board[right];

		int temp = lTemp + rTemp;
		if (abs(temp) < answer)
		{
			answer = abs(temp);
			leftAnswer = lTemp;
			rightAnswer = rTemp;
		}

		if (temp == 0)
			break;
		else if (temp > 0)
			right--;
		else
			left++;
	}

	cout << leftAnswer << " " << rightAnswer << "\n";

	return 0;
}