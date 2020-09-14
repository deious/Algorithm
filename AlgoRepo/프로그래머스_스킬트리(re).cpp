#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int len = skill_trees.size();
    int sLen = skill.size();
    
    for(int i = 0; i < len; i++)
    {
        int stLen = skill_trees[i].size();
        int sIndex = 0;
        bool check = false;
        bool aCheck = false;
        
        vector<pair<int, int>> v;
        
        for(int j = 0; j < sLen; j++)
        {   
            for(int k = 0; k < stLen; k++)
            {
                if(skill[j] == skill_trees[i][k])
                {
                    if(sIndex > k)
                    {
                        check = true;
                        aCheck = true;
                        break;
                    }
                    else
                    {
                        sIndex = k;
                        v.push_back(make_pair(j, sIndex));
                    }
                }
            }      
            if(check) break;
        }
                
        if(v.size() > 1 && !aCheck)
        {
            for(int j = 0;  j < v.size() - 1; j++)
            {
                if(v[0].first != 0)
                {
                    aCheck = true;
                    break;
                }
            
                if(v[j].first != v[j + 1].first - 1)
                {
                    aCheck = true;
                    break;
                }
            } 
        }
        else if(v.size() == 1 && !aCheck)
        {
            if(v[0].first != 0) aCheck = true;
        }
        
        if(!aCheck) answer++;
    }
   
    return answer;
}