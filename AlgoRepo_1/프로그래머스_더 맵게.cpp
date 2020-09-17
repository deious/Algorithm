#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int len = scoville.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < len; i++)
    {
        pq.push(scoville[i]);
    }
    
    while(pq.top() < K && pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a + b * 2);
        answer++;
    }
    
    if(pq.top() < K) return -1;
    else return answer;
}