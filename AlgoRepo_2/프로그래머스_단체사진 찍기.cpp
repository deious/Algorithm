#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<string> data) {
	int answer = 0;
	vector<char> v = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
	do
	{
		bool check = false;

		for (auto au : data)
		{
			char f1 = au[0];
			char f2 = au[2];
			char opr = au[3];
			int num = au[4] - '0';
			int distance = abs(find(v.begin(), v.end(), f1) - find(v.begin(), v.end(), f2)) - 1;

			if (opr == '=')
			{
				if (distance == num)
					continue;
				else
				{
					check = true;
					break;
				}
			}
			else if (opr == '<')
			{
				if (distance < num)
					continue;
				else
				{
					check = true;
					break;
				}
			}
			else if (opr == '>')
			{
				if (distance > num)
					continue;
				else
				{
					check = true;
					break;
				}
			}
		}

		if (!check)
			answer++;
	} while (next_permutation(v.begin(), v.end()));

	return answer;
}