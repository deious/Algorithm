#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    bool check;
    
    for(int i = 0; i < skill_trees.size(); i++)
    {
        vector<int> v;
        
        for(int j = 0; j < skill_trees[i].size(); j++)
        {
            for(int k = 0; k < skill.size(); k++)
            {
                if(skill_trees[i][j] == skill[k])
                {
                    v.push_back(skill_trees[i][j]);
                }
            }
        }
        
        check = false;
        
        for(int j = 0; j < v.size(); j++)
        {
           if(skill[j] != v[j])
           {
               check = true;
               break;
           }
        }
        
        if(!check) answer++;
    }
    return answer;
}