#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, string> parent;
unordered_map<string, int> revenue;

void UpdateRevenue(string name, int money)
{
	if (name == "None")
		return;

	int parentRevenue = money * 0.1;
	revenue[name] += (money - parentRevenue);

	if (parentRevenue == 0)
		return;

	UpdateRevenue(parent[name], parentRevenue);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
	vector<int> answer;

	int eLen = enroll.size();
	for (int i = 0; i < eLen; i++)
	{
		if (referral[i] == "-")
			parent[enroll[i]] = "None";
		else
			parent[enroll[i]] = referral[i];
	}

	int sLen = seller.size();
	for (int i = 0; i < sLen; i++)
		UpdateRevenue(seller[i], amount[i] * 100);

	for (int i = 0; i < eLen; i++)
		answer.push_back(revenue[enroll[i]]);

	return answer;
}