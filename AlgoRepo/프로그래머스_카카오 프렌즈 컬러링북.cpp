#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int mM,nN;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool check[100][100];

bool InRange(int x, int y)
{
    return x >= 0 && x < mM && y >= 0 & y < nN;
}

int bfs(int x, int y, vector<vector<int>> picture)
{
    int size = 1;
    int color = picture[x][y];
    
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    check[x][y] = true;
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(InRange(nx, ny) && !check[nx][ny] && picture[nx][ny] == color)
            {
                check[nx][ny] = true;
                q.push(make_pair(nx, ny));
                size++;
            }
        }
    }
    
    return size;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    mM = m;
    nN = n;
    
    memset(check, false, sizeof(check));
    
    vector<int> answer;
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!check[i][j] && picture[i][j] != 0)
            {
                max_size_of_one_area = max(max_size_of_one_area, bfs(i, j, picture));
                number_of_area++;
            }
        }
    }
    
    answer.push_back(number_of_area);
    answer.push_back(max_size_of_one_area);
    
    return answer;
}