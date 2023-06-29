#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool check[8];
int bLen, uLen;
set<string> s;

void solve(int index, string str, vector<string> &user_id, vector<string> &banned_id)
{
	if (index == bLen)
	{
		sort(str.begin(), str.end());
		s.insert(str);
		return;
	}

	string bid = banned_id[index];
	int bidLen = bid.size();

	for (int i = 0; i < uLen; i++)
	{
		string uid = user_id[i];

		if (uid.size() != bidLen)
			continue;

		if (check[i])
			continue;

		bool flag = true;
		for (int j = 0; j < bidLen; j++)
		{
			if (bid[j] == '*')
				continue;

			if (uid[j] != bid[j])
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			check[i] = true;
			solve(index + 1, str + to_string(i), user_id, banned_id);
			check[i] = false;
		}
	}

	return;
}


int solution(vector<string> user_id, vector<string> banned_id) {
	int answer = 0;

	uLen = user_id.size();
	bLen = banned_id.size();

	solve(0, "", user_id, banned_id);
	answer = s.size();

	return answer;
}
