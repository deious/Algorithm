#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> &numbers, int target, int sum, int index, int nLen)
{
    if (index == nLen)
    {
        if (sum == target)
        {
            answer++;
        }
        
        return;
    }
    
    dfs(numbers, target, sum + numbers[index], index + 1, nLen);
    dfs(numbers, target, sum - numbers[index], index + 1, nLen);
}

int solution(vector<int> numbers, int target) {
    int len = numbers.size();
    
    dfs(numbers, target, 0, 0, len);
    
    return answer;
}