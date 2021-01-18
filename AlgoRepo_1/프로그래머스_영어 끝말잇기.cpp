#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer(2, 0);
	set<string> s;
	s.insert(words[0]);

	int len = words[0].size();
	char c = words[0][len - 1];

	for (int i = 1; i < words.size(); i++)
	{
		int tempLen = words[i].size();

		if (!s.insert(words[i]).second || c != words[i][0])
		{
			answer[0] = i % n + 1;
			answer[1] = i / n + 1;
			break;
		}
		else c = words[i][tempLen - 1];
	}

	return answer;
}