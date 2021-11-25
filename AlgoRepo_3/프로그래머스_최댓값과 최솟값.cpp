#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(string s) {
	string answer = "";
	vector<int> v;
	stringstream ss;
	ss.str(s);
	int num;
	while (ss >> num)
		v.push_back(num);

	sort(v.begin(), v.end());
	int len = v.size();
	string minStr, maxStr;
	minStr = to_string(v[0]);
	maxStr = to_string(v[len - 1]);

	answer = minStr + " " + maxStr;
	return answer;
}