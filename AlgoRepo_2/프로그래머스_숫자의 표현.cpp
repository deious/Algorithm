#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	int start = 1;

	while (start <= n)
	{
		int num = 0;
		for (int i = start; i <= n; i++)
		{
			num += i;
			if (num == n)
			{
				answer++;
				break;
			}
			else if (num > n)
				break;
		}
		start++;
	}
	return answer;
}