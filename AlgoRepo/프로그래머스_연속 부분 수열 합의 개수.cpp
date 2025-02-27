#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
	int answer = 0;
	set<int> s;
	int len = elements.size();
	vector<int> v(elements);
	for (int i = 0; i < len; i++)
	{
		v.push_back(v[i]);
	}

	for (int i = 0; i < len; i++)
	{
		int sum = v[i];
		s.insert(sum);
		int cnt = 1;
		int end = i;
		while (cnt < len)
		{
			cnt++;
			end++;
			sum += v[end];
			s.insert(sum);
		}
	}

	return answer = s.size();
}