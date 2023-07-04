#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
	int answer = 0;
	int wLen = want.size();
	int dLen = discount.size();
	int nLen = number.size();
	int totalNum = 0;

	map<string, int> m;

	for (int i = 0; i < nLen; i++)
	{
		m[want[i]] += number[i];
		totalNum += number[i];
	}

	if (totalNum > dLen)
	{
		return 0;
	}

	for (int i = 0; i <= dLen - 10; i++)
	{
		map<string, int> m1;
		for (int j = i; j < i + 10; j++)
		{
			m1[discount[j]]++;
		}

		if (m == m1)
		{
			answer++;
		}
	}
	return answer;
}