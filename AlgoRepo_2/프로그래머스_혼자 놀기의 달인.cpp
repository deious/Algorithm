#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check[101];

int solution(vector<int> cards) {
	vector<int> v;

	int len = cards.size();
	for (int i = 0; i < len; i++)
	{
		int cnt = 0;
		int idx = i;

		while (true)
		{
			if (check[idx])
			{
				if (cnt)
				{
					v.push_back(cnt);
				}

				break;
			}

			cnt++;
			check[idx] = true;
			idx = cards[idx] - 1;
		}
	}

	if (v.size() <= 1)
	{
		return 0;
	}

	int size = v.size();
	sort(v.begin(), v.end());

	return v[size - 1] * v[size - 2];
}