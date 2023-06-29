#include <string>
#include <vector>

using namespace std;

void Calculate(vector<vector<int>> &v, int n, int start, int middle, int end)
{
	if (n == 1)
	{
		v.push_back({ start, end });
		return;
	}
	else
	{
		Calculate(v, n - 1, start, end, middle);
		v.push_back({ start, end });
		Calculate(v, n - 1, middle, start, end);
	}

	return;
}

vector<vector<int>> solution(int n) {
	vector<vector<int>> answer;
	Calculate(answer, n, 1, 2, 3);
	return answer;
}