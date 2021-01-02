#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ansNum, nCount, answer = 9;

void calculate(int num, int count)
{
	if (count > 8) return;

	if (num == ansNum)
	{
		answer = min(answer, count);
		return;
	}

	int tempNum = 0;

	for (int i = 1; i <= 7; i++)
	{
		tempNum = tempNum * 10 + nCount;
		calculate(num + tempNum, count + i);
		calculate(num - tempNum, count + i);
		if (num != 0)
		{
			calculate(num * tempNum, count + i);
			calculate(num / tempNum, count + i);
		}
	}
}

int solution(int N, int number) {
	ansNum = number, nCount = N;
	calculate(0, 0);

	if (answer == 9) return -1;
	else return answer;
}