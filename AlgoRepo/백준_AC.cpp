#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		string p;
		cin >> p;

		int n;
		cin >> n;

		string s;
		cin >> s;

		deque<int> dq;
		string temp = "";
		for (int i = 1; i < s.size(); i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
				temp.push_back(s[i]);
			else if (s[i] == ',')
			{
				dq.push_back(stoi(temp));
				temp.clear();
			}
			else if (s[i] == ']' && temp != "")
				dq.push_back(stoi(temp));
		}

		bool check = false, endCheck = false;;
		for (int i = 0; i < p.size(); i++)
		{
			if (p[i] == 'R')
				check = !check;
			else
			{
				if (!dq.empty())
				{
					if (!check)
						dq.pop_front();
					else
						dq.pop_back();
				}
				else
				{
					endCheck = true;
					cout << "error\n";
					break;
				}
			}
		}

		if (!endCheck)
		{
			cout << "[";
			int len = dq.size();
			if (!check)
			{
				for (int i = 0; i < len; i++)
				{
					if (i != len - 1)
						cout << dq.front() << ",";
					else
						cout << dq.front();

					dq.pop_front();
				}
			}
			else
			{
				for (int i = 0; i < len; i++)
				{
					if (i != len - 1)
						cout << dq.back() << ",";
					else
						cout << dq.back();

					dq.pop_back();
				}
			}
			cout << "]\n";
		}
	}

	return 0;
}