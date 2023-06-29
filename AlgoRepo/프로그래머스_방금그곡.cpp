#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string ChangeSound(string m, map<string, char> msc)
{
	string s = "";
	int len = m.size();
	for (int i = 0; i < len; i++)
	{
		if (m[i + 1] == '#')
		{
			s += msc[m.substr(i, 2)];
			i++;
		}
		else
			s += m[i];
	}

	return s;
}

string solution(string m, vector<string> musicinfos) {
	string answer = "(None)";
	map<string, char> msc;

	msc["C#"] = 'H';
	msc["D#"] = 'I';
	msc["F#"] = 'J';
	msc["G#"] = 'K';
	msc["A#"] = 'L';

	string melody = ChangeSound(m, msc);
	int sHour, sMin, eHour, eMin, totalTime, bTime = 0;
	string musicName = "", tempMelody = "";
	int len = musicinfos.size();

	for (int i = 0; i < len; i++)
	{
		sHour = stoi(musicinfos[i].substr(0, 2)) * 60;
		sMin = stoi(musicinfos[i].substr(3, 2));
		eHour = stoi(musicinfos[i].substr(6, 2)) * 60;
		eMin = stoi(musicinfos[i].substr(9, 2));
		totalTime = eHour + eMin - sHour - sMin;

		int index = 12;
		for (int j = index; j < musicinfos[i].size(); j++)
		{
			if (musicinfos[i][j] == ',')
			{
				musicName = musicinfos[i].substr(index, j - index);
				tempMelody = musicinfos[i].substr(j + 1);
				break;
			}
		}

		tempMelody = ChangeSound(tempMelody, msc);

		string temp = "";
		int tLen = tempMelody.size();
		int ttLen;
		if (tLen < totalTime)
		{
			ttLen = totalTime / tLen;
			for (int j = 0; j < ttLen; j++)
				temp += tempMelody;

			ttLen = totalTime % tLen;
			for (int j = 0; j < ttLen; j++)
				temp += tempMelody[j];
		}
		else
			temp = tempMelody.substr(0, totalTime);

		if (temp.find(melody) != string::npos)
		{
			if (bTime < totalTime)
			{
				answer = musicName;
				bTime = totalTime;
			}
		}
	}

	return answer;
}