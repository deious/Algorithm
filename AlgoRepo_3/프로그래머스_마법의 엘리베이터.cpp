#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
	int answer = 0;

	while (storey)
	{
		int cur = storey % 10;
		int next = (storey / 10) % 10;

		if (cur > 5)
		{
			answer += 10 - cur;
			storey += 10;
		}
		else if (cur == 5)
		{
			answer += 5;
			storey += next >= 5 ? 10 : 0;
		}
		else
		{
			answer += cur;
		}

		storey /= 10;
	}

	return answer;
}