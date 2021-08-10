#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    queue<string> que;
    map<string, int> mp;
    int gems_size = 0;
    int start = 0;
    int end = 100001;
    int tmp = 0;
    
    for(auto i : gems) {
        mp[i] = 1;
    }
    
    gems_size = mp.size();
    mp.clear();
    
    for(int i = 0; i < gems.size(); i++) {
        if(mp[gems[i]] == 0) {
            mp[gems[i]] = 1;
        }
        
        else {
            mp[gems[i]] += 1;
        }
        
        que.push(gems[i]);
        
        while(1) {
            if(mp[que.front()] > 1) {
                mp[que.front()] -= 1;
                que.pop();
                tmp++;
            }
            
            else {
                break;
            }
        }
        
        if(mp.size() == gems_size && que.size() < end) {
            end = que.size();
            start = tmp;
        }
    }
    
    answer = {0, 0};
    
    answer[0] = start + 1;
    answer[1] = start + end;
    
    return answer;
}