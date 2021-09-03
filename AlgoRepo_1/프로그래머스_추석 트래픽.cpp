#include <string>
#include <vector>

using namespace std;

int solution(vector<string> lines) {
	int answer = 0;
	int len = lines.size();
	vector<int> start, end;

	string h, m, s, ms, process;
	int sH, sM, sS, sMs, sProcess;
	for (int i = 0; i < len; i++)
	{
		h = lines[i].substr(11, 2);
		m = lines[i].substr(14, 2);
		s = lines[i].substr(17, 2);
		ms = lines[i].substr(20, 3);
		process = lines[i].substr(24, 5);

		sH = stoi(h) * 3600 * 1000;
		sM = stoi(m) * 60 * 1000;
		sS = stoi(s) * 1000;
		sMs = stoi(ms);
		sProcess = stof(process) * 1000;

		start.push_back(sH + sM + sS + sMs - sProcess + 1);
		end.push_back(sH + sM + sS + sMs);
	}

	for (int i = 0; i < len; i++)
	{
		int count = 0;
		for (int j = i; j < len; j++)
		{
			if (end[i] + 1000 > start[j])
				count++;
		}

		if (count > answer)
			answer = count;
	}
	return answer;
}