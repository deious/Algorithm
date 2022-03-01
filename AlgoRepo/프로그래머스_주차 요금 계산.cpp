#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int TimeCheck(string s1, string s2)
{
	int startHour = stoi(s1.substr(0, 2)) * 60;
	int startMinute = stoi(s1.substr(3, 2));
	int endHour = stoi(s2.substr(0, 2)) * 60;
	int endMinute = stoi(s2.substr(3, 2));

	return (endHour + endMinute) - (startHour + startMinute);
}

vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;
	stringstream ss;
	string time, carNum, status;
	map<string, vector<string>> m;

	for (string s : records)
	{
		ss.str(s);
		ss >> time >> carNum >> status;
		m[carNum].push_back(time);
		ss.clear();
	}

	int sum = 0;
	int money = 0;

	for (auto au : m)
	{
		sum = 0;
		money = 0;
		if (au.second.size() % 2 == 1)
			au.second.push_back("23:59");

		for (int i = 0; i < au.second.size() - 1; i += 2)
			sum += TimeCheck(au.second[i], au.second[i + 1]);

		sum -= fees[0];
		money += fees[1];
		if (sum <= 0)
			answer.push_back(money);
		else
		{
			int temp = 0;
			if (sum % fees[2] == 0)
			{
				temp = sum / fees[2];
				money += fees[3] * temp;
			}
			else
			{
				temp = sum / fees[2];
				temp++;
				money += fees[3] * temp;
			}

			answer.push_back(money);
		}
	}

	return answer;
}