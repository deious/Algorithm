#include <iostream>

using namespace std;

long long CCW(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c)
{
	long long num = a.first * b.second + b.first * c.second + c.first * a.second - (b.first * a.second + c.first * b.second + a.first * c.second);

	if (num > 0)
		return 1;
	else if (num == 0)
		return 0;
	else
		return -1;
}

bool LineCheck(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c, pair<long long, long long> d)
{
	int abc = CCW(a, b, c);
	int abd = CCW(a, b, d);
	int cda = CCW(c, d, a);
	int cdb = CCW(c, d, b);

	if (abc * abd == 0 && cda * cdb == 0)
	{
		if (a > b)
			swap(a, b);
		if (c > d)
			swap(c, d);

		return a <= d && c <= b;
	}

	return abc * abd <= 0 && cda * cdb <= 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	pair<long long, long long> pos[4];

	for (int i = 0; i < 4; i++)
		cin >> pos[i].first >> pos[i].second;

	if (LineCheck(pos[0], pos[1], pos[2], pos[3]))
		cout << "1\n";
	else
		cout << "0\n";

	return 0;
}