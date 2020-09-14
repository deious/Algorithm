#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int len = moves.size();
    int bLen = board.size();
    int index = 0;
    vector<int> v(len);
    
    for(int i = 0; i < len; i++)
    {
        int move = moves[i] - 1;
        
        for(int j = 0; j < bLen; j++)
        {
            if(board[j][move] != 0)
            {
                if(v[0] == 0) 
                {
                    v[index] = board[j][move];
                }
                else if(v[index] != board[j][move])
                {
                    v[++index] = board[j][move];
                }
                else 
                {
                    v[index] = 0;
                    index--;
                    if(index < 0) index = 0;
                    answer += 2;
                }
                
                board[j][move] = 0;
                break;
            }
        }
    }
    return answer;
}