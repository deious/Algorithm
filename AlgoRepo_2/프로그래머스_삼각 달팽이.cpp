#include <string>
#include <vector>

using namespace std;

int check[1000][1000];

vector<int> solution(int n) {
    vector<int> answer;
    
    int num = 1;
    int dir = 0;
    int x = 0, y = 0;
    check[0][0] = 1;
    
    for(int i = 0; i < n; i++)
    {
        switch(dir)
        {
            case 0:
                for(int j = i; j < n; j++)
                {
                    check[x++][y] = num++;
                }
                x--;
                y++;
                dir = 1;
                break;
            case 1:
                for(int j = i; j < n; j++)
                {
                    check[x][y++] = num++;
                }
                x--;
                y -= 2;
                dir = 2;
                break;
            case 2:
                for(int j = i; j < n; j++)
                {
                    check[x--][y--] = num++;
                }
                x += 2;
                y++;
                dir = 0;
                break;
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i + 1; j++)
        {
            answer.push_back(check[i][j]);
        }
    }
    return answer;
}