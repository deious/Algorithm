#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
	int answer = 0;
	sort(arrayA.begin(), arrayA.end());
	sort(arrayB.begin(), arrayB.end());

	vector<int> v, v1;
	bool check = false;

	for (int i = 2; i <= arrayA[0]; i++)
	{
		check = false;
		for (int j = 0; j < arrayA.size(); j++)
		{
			if (arrayA[j] % i != 0)
			{
				check = true;
				break;
			}
		}

		if (!check)
		{
			v.push_back(i);
		}
	}

	for (int i = 2; i <= arrayB[0]; i++)
	{
		check = false;
		for (int j = 0; j < arrayB.size(); j++)
		{
			if (arrayB[j] % i != 0)
			{
				check = true;
				break;
			}
		}

		if (!check)
		{
			v1.push_back(i);
		}
	}

	sort(v.rbegin(), v.rend());
	sort(v1.rbegin(), v1.rend());
	for (int i = 0; i < v.size(); i++)
	{
		check = false;
		for (int j = 0; j < arrayB.size(); j++)
		{
			if (arrayB[j] % v[i] == 0)
			{
				check = true;
				break;
			}
		}

		if (!check)
		{
			answer = v[i];
			break;
		}
	}

	for (int i = 0; i < v1.size(); i++)
	{
		check = false;
		for (int j = 0; j < arrayA.size(); j++)
		{
			if (arrayA[j] % v1[i] == 0)
			{
				check = true;
				break;
			}
		}

		if (!check)
		{
			if (answer < v1[i])
			{
				answer = v1[i];
			}
			break;
		}
	}

	return answer;
}