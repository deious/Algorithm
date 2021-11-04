#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> v[4][3][3][3];
unordered_map<string, int> m;

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;

	m["-"] = 0;
	m["cpp"] = 1;
	m["java"] = 2;
	m["python"] = 3;
	m["backend"] = 1;
	m["frontend"] = 2;
	m["junior"] = 1;
	m["senior"] = 2;
	m["chicken"] = 1;
	m["pizza"] = 2;

	string s[4];
	int num;

	for (auto au : info)
	{
		istringstream ss(au);
		ss >> s[0] >> s[1] >> s[2] >> s[3] >> num;
		int arr[4] = { m[s[0]], m[s[1]], m[s[2]], m[s[3]] };

		for (int i = 0; i < (1 << 4); i++)
		{
			int idx[4] = { 0, };
			for (int j = 0; j < 4; j++)
			{
				if (i & (1 << j))
					idx[j] = arr[j];
			}
			v[idx[0]][idx[1]][idx[2]][idx[3]].push_back(num);
		}
	}

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				for (int l = 0; l < 3; l++)
					sort(v[i][j][k][l].begin(), v[i][j][k][l].end());

	for (auto au : query)
	{
		stringstream ss(au);
		string a, b, c, d, str;
		ss >> a >> str >> b >> str >> c >> str >> d >> num;
		auto &aa = v[m[a]][m[b]][m[c]][m[d]];

		vector<int>::iterator low = lower_bound(aa.begin(), aa.end(), num);
		answer.push_back(aa.end() - low);
	}

	return answer;
}