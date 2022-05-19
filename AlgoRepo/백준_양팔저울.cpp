#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int weight[30];
bool check[31][15001];

int weightNum, beadNum;

set<int> s;

void Calculate(int sum, int index)
{
	if (index >= weightNum)
		return;

	if (check[index][sum])
		return;

	check[index][sum] = true;

	Calculate(sum + weight[index], index + 1);
	s.insert(sum + weight[index]);
	Calculate(sum, index + 1);
	Calculate(abs(sum - weight[index]), index + 1);
	s.insert(abs(sum - weight[index]));

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> weightNum;
	for (int i = 0; i < weightNum; i++)
	{
		cin >> weight[i];
		s.insert(weight[i]);
	}

	cin >> beadNum;
	Calculate(0, 0);

	int temp = 0;
	for (int i = 0; i < beadNum; i++)
	{
		cin >> temp;
		if (s.find(temp) != s.end())
			cout << "Y ";
		else
			cout << "N ";
	}

	return 0;
}