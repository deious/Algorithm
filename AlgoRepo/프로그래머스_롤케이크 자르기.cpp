#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
	int answer = 0;
	int len = topping.size();
	map<int, int> m, m1;
	for (int i = 0; i < len; i++)
	{
		m[topping[i]]++;
	}

	for (int i = 0; i < len - 1; i++)
	{
		m[topping[i]]--;
		m1[topping[i]]++;

		if (m[topping[i]] == 0)
		{
			m.erase(topping[i]);
		}

		if (m.size() == m1.size())
		{
			answer++;
		}
	}

	return answer;
}