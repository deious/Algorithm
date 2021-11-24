#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
	int len = s.size();
	bool check = true;
	s[0] = toupper(s[0]);

	for (int i = 1; i < len; i++)
	{
		if (s[i] == ' ')
		{
			check = false;
			continue;
		}

		if (!check)
		{
			s[i] = toupper(s[i]);
			check = true;
		}
		else
			s[i] = tolower(s[i]);
	}

	return s;
}