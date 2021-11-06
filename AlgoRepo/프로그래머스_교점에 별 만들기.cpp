#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
	vector<pair<long, long>> star;
	int len = line.size();

	long minX = LONG_MAX;
	long minY = LONG_MAX;
	long maxX = LONG_MIN;
	long maxY = LONG_MIN;

	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			long A = line[i][0];
			long B = line[i][1];
			long E = line[i][2];
			long C = line[j][0];
			long D = line[j][1];
			long F = line[j][2];
			long numeratorX = (B * F) - (E * D);
			long numeratorY = (E * C) - (A * F);
			long denominator = (A * D) - (B * C);

			if (denominator == 0)
				continue;
			if (numeratorX % denominator != 0 || numeratorY % denominator != 0)
				continue;

			long x = numeratorX / denominator;
			long y = numeratorY / denominator;

			minX = min(minX, x);
			minY = min(minY, y);
			maxX = max(maxX, x);
			maxY = max(maxY, y);

			star.push_back({ x, y });
		}
	}

	string col = string(maxX - minX + 1, '.');
	vector<string> answer(maxY - minY + 1, col);

	for (auto st : star)
		answer[abs(st.second - maxY)][abs(st.first - minX)] = '*';

	return answer;
}