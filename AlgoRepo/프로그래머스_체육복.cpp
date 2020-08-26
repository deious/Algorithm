#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector<int> v(n);

	for (int i = 0; i < v.size(); i++)
	{
		v[i] = 1;
	}

	for (int i = 0; i < reserve.size(); i++)
	{
		int temp = reserve[i];
		v[temp - 1]++;
	}

	for (int i = 0; i < lost.size(); i++)
	{
		int temp = lost[i];
		v[temp - 1]--;
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == 2 && v[i - 1] == 0 && i > 0)
		{
			v[i]--;
			v[i - 1]++;
		}

		if (v[i] == 2 && v[i + 1] == 0 && i < v.size() - 1)
		{
			v[i]--;
			v[i + 1]++;
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] >= 1)
		{
			answer++;
		}
	}
	return answer;
}