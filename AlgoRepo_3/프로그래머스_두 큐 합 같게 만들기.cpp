#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
	int temp;
	long long temp1, temp2;
	for (int i = 0; i < queue1.size(); i++)
	{
		temp1 += queue1[i];
		temp2 += queue2[i];
	}

	queue<int> q1, q2;

	for (int i = 0; i < queue1.size(); i++)
	{
		q1.push(queue1[i]);
		q2.push(queue2[i]);
	}

	int answer = 0;
	while (temp1 != temp2)
	{
		if (temp1 > temp2)
		{
			temp = q1.front();
			q1.pop();
			q2.push(temp);
			temp1 -= temp;
			temp2 += temp;
		}
		else
		{
			temp = q2.front();
			q2.pop();
			q1.push(temp);
			temp2 -= temp;
			temp1 += temp;
		}

		answer++;

		if (answer > 1200000)
		{
			return -1;
		}
	}

	return answer;
}