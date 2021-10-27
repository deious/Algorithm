#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> w;
vector<int> d;
int N, answer;

void Calculate(int cnt, int pos, int visit)
{
	if (cnt > d.size())
		return;
	if (cnt >= answer)
		return;

	int len = w.size();
	for (int i = 0; i < len; i++)
	{
		int next = (pos + i) % len;
		int diff = w[next] - w[pos];

		if (next < pos)
			diff += N;

		if (diff > d[d.size() - cnt])
			break;

		visit |= 1 << next;
	}

	if (visit == (1 << len) - 1)
	{
		answer = cnt;
		return;
	}

	for (int i = 0; i < len; i++)
	{
		if (visit & (1 << i))
			continue;
		Calculate(cnt + 1, i, visit);
	}
}

int solution(int n, vector<int> weak, vector<int> dist) {
	sort(dist.begin(), dist.end());
	N = n;
	w = weak;
	d = dist;
	answer = 2100000000;

	int len = weak.size();
	for (int i = 0; i < len; i++)
		Calculate(1, i, 0);

	if (answer == 2100000000)
		return -1;

	return answer;
}