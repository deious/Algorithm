#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id) {
	string answer = "";
	transform(new_id.cbegin(), new_id.cend(), new_id.begin(), ::tolower);

	for (int i = 0; i < new_id.size();)
	{
		if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.' || (new_id[i] >= '0' && new_id[i] <= '9') || (new_id[i] >= 'a' && new_id[i] <= 'z'))
			i++;
		else
			new_id.erase(new_id.begin() + i);
	}

	for (int i = 0; i < new_id.size();)
	{
		int index = 0;
		if (new_id[i] == '.' && i != new_id.size() - 1)
		{
			index = i;
			for (int j = i + 1; j < new_id.size(); j++)
			{
				if (new_id[i] == new_id[j])
					index++;
				else
					break;
			}

			if (i != index)
				new_id.erase(new_id.begin() + i, new_id.begin() + index);
			else
				i++;
		}
		else
			i++;
	}

	if (new_id[0] == '.')
		new_id.erase(new_id.begin());

	if (new_id[new_id.size() - 1] == '.')
		new_id.erase(new_id.begin() + new_id.size() - 1);

	if (new_id.size() == 0)
		new_id.push_back('a');

	if (new_id.size() >= 16)
		new_id.erase(new_id.begin() + 15, new_id.end());
	if (new_id[new_id.size() - 1] == '.')
		new_id.pop_back();

	if (new_id.size() <= 2)
	{
		int len = new_id.size();
		for (int i = len; i < 3; i++)
			new_id.push_back(new_id[i - 1]);
	}

	return new_id;
}