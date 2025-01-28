#include <iostream>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	set<int> cycle;
	int n;
	cin >> n;

	while (cycle.insert(n).second)
	{
		int fNum, sNum, addNum;
		if (n >= 10)
		{
			fNum = n / 10;
			sNum = n % 10;
		}
		else
		{
			fNum = 0;
			sNum = n % 10;
		}

		addNum = (fNum + sNum) % 10;
		n = sNum * 10 + addNum;
	}

	cout << cycle.size() << "\n";

	return 0;
}