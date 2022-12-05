#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
	int answer = 0;
	vector<int> v(number + 1);
	for (int i = 1; i <= number; i++)
	{
		for (int j = 1; j <= number / i; j++)
		{
			v[i * j]++;
		}
	}

	for (int i = 1; i <= number; i++)
	{
		if (v[i] > limit)
		{
			answer += power;
		}
		else
		{
			answer += v[i];
		}
	}

	return answer;
}