#include <iostream>
#include <vector>

using namespace std;

bool check[200000001];

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;
	int sIndex = 0;
	int pos = 1;

	while (pos <= n)
	{
		if (pos >= stations[sIndex] - w && pos <= stations[sIndex] + w)
		{
			pos = stations[sIndex] + w + 1;
			sIndex++;
		}
		else
		{
			pos += w * 2 + 1;
			answer++;
		}
	}

	return answer;
}