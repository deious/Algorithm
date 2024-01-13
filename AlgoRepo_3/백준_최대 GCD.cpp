#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int GCD(int a, int b)
{
	int t;
	while (b)
	{
		t = a % b;
		a = b;
		b = t;
	}

	return a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, temp;
	int maxGcd = -1;
	string line, num;
	vector<int> v;

	cin >> N;
	cin.ignore();

	while (N--)
	{
		v.clear();
		maxGcd = -1;

		getline(cin, line);
		stringstream sstream(line);
		while (getline(sstream, num, ' '))
		{
			v.push_back(stoi(num));
		}

		for (int i = 0; i < v.size() - 1; i++)
		{
			for (int j = i + 1; j < v.size(); j++)
			{
				temp = GCD(v[i], v[j]);
				maxGcd = maxGcd < temp ? temp : maxGcd;
			}
		}

		cout << maxGcd << "\n";
	}

	return 0;
}