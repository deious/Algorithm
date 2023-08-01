#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int room[1450];

int solution(vector<vector<string>> book_time) {
	int answer = 0;
	int len = book_time.size();

	for (int i = 0; i < len; i++)
	{
		int s = stoi(book_time[i][0].substr(0, 2)) * 60 + stoi(book_time[i][0].substr(3, 2));
		int e = stoi(book_time[i][1].substr(0, 2)) * 60 + stoi(book_time[i][1].substr(3, 2)) + 10;

		for (int j = s; j < e; j++)
		{
			room[j]++;
		}
	}

	for (int i = 0; i <= 1450; i++)
	{
		answer = max(answer, room[i]);
	}

	return answer;
}