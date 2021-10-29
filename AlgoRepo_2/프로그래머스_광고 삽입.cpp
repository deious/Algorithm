#include <string>
#include <vector>
#include <queue>

using namespace std;

int adv[360000];

int TimeToSecond(string s)
{
	return stoi(s.substr(0, 2)) * 3600 + stoi(s.substr(3, 2)) * 60 + stoi(s.substr(6, 2));
}

string SecondToTime(int index)
{
	string str = "";
	int s = index % 60;
	index /= 60;
	int m = index % 60;
	index /= 60;
	int h = index;

	if (h < 10)
	{
		str.push_back('0');
		str += to_string(h);
	}
	else
		str += to_string(h);

	str.push_back(':');

	if (m < 10)
	{
		str.push_back('0');
		str += to_string(m);
	}
	else
		str += to_string(m);

	str.push_back(':');

	if (s < 10)
	{
		str.push_back('0');
		str += to_string(s);
	}
	else
		str += to_string(s);

	return str;
}

string solution(string play_time, string adv_time, vector<string> logs) {
	string answer = "";
	int pTime = TimeToSecond(play_time);
	int aTime = TimeToSecond(adv_time);

	int len = logs.size();
	for (int i = 0; i < len; i++)
	{
		int start = TimeToSecond(logs[i]);
		int end = TimeToSecond(logs[i].substr(9, 8));

		for (int j = start; j < end; j++)
			adv[j]++;
	}

	queue<int> q;
	int index = 0;
	long sum = 0;
	long maxSum = 0;

	for (int i = 0; i < aTime; i++)
	{
		sum += adv[i];
		q.push(adv[i]);
	}
	maxSum = sum;

	for (int i = aTime; i < pTime; i++)
	{
		sum += adv[i];
		q.push(adv[i]);
		sum -= q.front();
		q.pop();

		if (sum > maxSum)
		{
			index = i - aTime + 1;
			maxSum = sum;
		}
	}

	return answer = SecondToTime(index);
}