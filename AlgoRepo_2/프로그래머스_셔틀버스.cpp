#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	int len = timetable.size();

	int h, mi;
	vector<int> time;
	for (int i = 0; i < len; i++)
	{
		h = stoi(timetable[i].substr(0, 2)) * 60;
		mi = stoi(timetable[i].substr(3, 2));
		time.push_back(h + mi);
	}

	sort(time.begin(), time.end());

	int index = 0;
	int busPeople;
	int start = 540;
	int temp;

	for (int i = 0; i < n; i++, start += t)
	{
		busPeople = 0;
		for (int j = index; j < len; j++)
		{
			if (time[j] <= start)
			{
				index++;
				busPeople++;

				if (busPeople == m)
					break;
			}
		}

		if (i == n - 1)
		{
			if (busPeople == m)
				temp = time[index - 1] - 1;
			else
				temp = start;
		}
	}

	int hour = temp / 60;
	if (hour > 9)
		answer += (to_string(hour) + ":");
	else
		answer += ("0" + to_string(hour) + ":");

	int minute = temp % 60;
	if (minute < 10)
		answer += ("0" + to_string(minute));
	else
		answer += to_string(minute);

	return answer;
}