#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

long long calculate(long long x, long long y, char opr)
{
	if (opr == '+')
		return x + y;
	else if (opr == '-')
		return x - y;
	else
		return x * y;
}

long long solution(string expression) {
	long long answer = LLONG_MIN;
	vector<long long> v;
	vector<char> vc;
	vector<char> exp = { '+', '-', '*' };
	sort(exp.begin(), exp.end());

	int len = expression.size();
	string s = "";
	for (int i = 0; i < len; i++)
	{
		if (expression[i] - '0' >= 0 && expression[i] - '0' <= 9)
			s += expression[i];
		else
		{
			v.push_back(stoi(s));
			s = "";
			vc.push_back(expression[i]);
		}
	}
	v.push_back(stoi(s));

	do
	{
		vector<long long> tv = v;
		vector<char> tvc = vc;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < tvc.size(); j++)
			{
				if (exp[i] == tvc[j])
				{
					tv[j] = calculate(tv[j], tv[j + 1], tvc[j]);
					tv.erase(tv.begin() + j + 1);
					tvc.erase(tvc.begin() + j);
					j--;
				}
			}
		}

		if (tv[0] < 0)
			tv[0] *= -1;
		if (tv[0] > answer)
			answer = tv[0];
	} while (next_permutation(exp.begin(), exp.end()));

	return answer;
}