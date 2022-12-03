#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
	vector<int> answer;
	vector<int> v;
	int len = score.size();

	for (int i = 0; i < len; i++)
	{
		if (v.size() < k)
		{
			v.push_back(score[i]);
			sort(v.rbegin(), v.rend());
		}
		else if (score[i] > v[k - 1])
		{
			v[k - 1] = score[i];
			sort(v.rbegin(), v.rend());
		}

		answer.push_back(v[v.size() - 1]);
	}

	return answer;
}