#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer = {1, (int)gems.size()};
    int start = 0, end = 0;
    int dis = gems.size() - 1;
    map<string, int> mp;
    int total;
    
    for(string i : gems) {
        mp[i]++;
    }
    
    total = mp.size();
    mp.clear();
    
    while(1) {
        if(mp.size() == total) {
            if(end - start < dis) {
                dis = end - start;
                answer[0] = start + 1;
                answer[1] = end;
            }
            
            if(mp[gems[start]] == 1) {
                mp.erase(gems[start]);
                start++;
            }
            
            else {
                mp[gems[start]]--;
                start++;
            }
        }
        
        else if(end == gems.size()) {
            break;
        }
        
        else {
            mp[gems[end]]++;
            end++;
        }
    }
    
    return answer;
}