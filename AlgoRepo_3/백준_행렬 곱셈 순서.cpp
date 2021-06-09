#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int calCount[500][500];
vector<pair<int, int>> v;
int N;

int calculate(int begin, int end) 
{
	if (begin == end)
		return 0;

	int &num = calCount[begin][end];

	if (num)
		return num;

	num = 2100000000;

	for (int i = begin; i < end; i++)
		num = min(num, calculate(begin, i) + calculate(i + 1, end) + v[begin].first * v[i].second * v[end].second);

	return num;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	cout << calculate(0, N - 1) << "\n";

	return 0;
}
