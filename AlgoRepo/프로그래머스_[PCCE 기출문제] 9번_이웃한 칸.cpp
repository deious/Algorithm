#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int N;

bool InRange(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < N;
}

int BFS(int x, int y, int cnt, vector<vector<string>>& board)
{
    queue<pair<int, int>> q;
    q.push({ x, y });

    while (!q.empty())
    {
        int tempX = q.front().first;
        int tempY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = tempX + dx[i];
            int ny = tempY + dy[i];

            if (InRange(nx, ny) && board[tempX][tempY] == board[nx][ny])
            {
                cnt++;
            }
        }
    }

    return cnt;
}

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    N = board.size();

    answer = BFS(h, w, 0, board);

    return answer;
}