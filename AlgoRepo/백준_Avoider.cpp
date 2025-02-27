#include <iostream>

using namespace std;

long long moveCnt[29];

int endNum;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int start;
	long long answer = 0;
	cin >> start >> endNum;

	moveCnt[1] = 1;
	moveCnt[2] = 2;
	moveCnt[3] = 5;
	moveCnt[4] = 12;
	moveCnt[5] = 30;
	moveCnt[6] = 73;
	moveCnt[7] = 183;
	moveCnt[8] = 456;
	moveCnt[9] = 1151;
	moveCnt[10] = 2900;
	moveCnt[11] = 7361;
	moveCnt[12] = 18684;
	moveCnt[13] = 47652;
	moveCnt[14] = 121584;
	moveCnt[15] = 311259;
	moveCnt[16] = 797311;
	moveCnt[17] = 2047384;
	moveCnt[18] = 5260692;
	moveCnt[19] = 13542718;
	moveCnt[20] = 34884239;
	moveCnt[21] = 89991344;
	moveCnt[22] = 232282110;
	moveCnt[23] = 600281932;
	moveCnt[24] = 1552096361;
	moveCnt[25] = 4017128206;
	moveCnt[26] = 10401997092;
	moveCnt[27] = 26957667445;
	moveCnt[28] = 69892976538;

	for (int i = start; i <= endNum; i++)
	{
		answer += moveCnt[i];
	}

	cout << answer << "\n";

	return 0;
}