#include <iostream>
#include <queue>
#include <string>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long s, t;
	cin >> s >> t;
	string st = "";

	if (s == t)
	{
		cout << "0" << "\n";
		return 0;
	}

	queue<pair<long long, string>> q;
	q.push(make_pair(s, st));
	map<long long, string> m;
	m.insert(make_pair(s, st));

	while (!q.empty())
	{
		long long x = q.front().first;
		string ss = q.front().second;
		q.pop();

		if (x == t)
		{
			cout << ss << "\n";
			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			long long tempX = x;
			string tempString = ss;

			if (i == 0 && !m.count(tempX * tempX) && ((tempX * tempX) > 0))
			{
				tempX *= tempX;
				tempString += '*';
				q.push(make_pair(tempX, tempString));
				m.insert(make_pair(tempX, tempString));
			}
			else if (i == 1 && !m.count(tempX + tempX) && ((tempX + tempX) > 0))
			{
				tempX += tempX;
				tempString += '+';
				q.push(make_pair(tempX, tempString));
				m.insert(make_pair(tempX, tempString));
			}
			else if (i == 2 && !m.count(tempX - tempX) && (tempX - tempX >= 0))
			{
				tempX -= tempX;
				tempString += '-';
				q.push(make_pair(tempX, tempString));
				m.insert(make_pair(tempX, tempString));
			}
			else
			{
				if (tempX == 0 || m.count(tempX / tempX))
					continue;
				tempX /= tempX;
				tempString += '/';
				q.push(make_pair(tempX, tempString));
				m.insert(make_pair(tempX, tempString));
			}
		}
	}

	cout << "-1" << "\n";

	return 0;
}