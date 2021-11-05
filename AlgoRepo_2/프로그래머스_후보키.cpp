#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool check(vector<int> answer, int bit)
{
	int len = answer.size();
	for (int i = 0; i < len; i++)
	{
		if ((answer[i] & bit) == answer[i])
			return false;
	}

	return true;
}

int solution(vector<vector<string>> relation) {
	vector<int> answer;
	int row = relation.size();
	int col = relation[0].size();

	for (int i = 0; i < (1 << col); i++)
	{
		set<string> s;
		for (int j = 0; j < row; j++)
		{
			string str = "";
			for (int k = 0; k < col; k++)
			{
				if (i & (1 << k))
					str += relation[j][k];
			}
			s.insert(str);
		}

		if (s.size() == row && check(answer, i))
			answer.push_back(i);
	}

	return answer.size();
}