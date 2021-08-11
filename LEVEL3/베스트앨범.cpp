#include<string>
#include<vector>
#include<map>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> mp;
    map<string, map<int, int>> list;
    
    for(int i = 0; i < genres.size(); i++) {
        mp[genres[i]] += plays[i];
        list[genres[i]][i] = plays[i];
    }
    
    while(mp.size() > 0) {
        string s;
        int max = 0;
        
        for(auto i : mp) {
            if(i.second > max) {
                max = i.second;
                s = i.first;
            }
        }
        
        for(int i = 0; i < 2; i++) {
            int idx = -1;
            int k = 0;
            
            for(auto i : list[s]) {
                if(i.second > k) {
                    k = i.second;
                    idx = i.first;
                }
            }
            
            if(idx == -1) {
                break;
            }
            
            answer.push_back(idx);
            list[s].erase(idx);
        }
        
        mp.erase(s);
    }
    
    return answer;
}