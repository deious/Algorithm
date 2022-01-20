#include <iostream>

using namespace std;

bool num[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long minNum, maxNum;
	cin >> minNum >> maxNum;

	for (long long i = 2; i * i <= maxNum; i++)
	{
		long long startNum = minNum / (i * i);
		
		if (minNum % (i * i))
			startNum++;

		while (startNum * i * i <= maxNum)
		{
			num[startNum * i * i - minNum] = true;
			startNum++;
		}
	}

	int answer = 0;
	for (int i = 0; i <= maxNum - minNum; i++)
	{
		if (!num[i])
			answer++;
	}

	cout << answer << "\n";

	return 0;
}