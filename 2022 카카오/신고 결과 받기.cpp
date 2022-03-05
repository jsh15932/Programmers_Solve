#include<bits/stdc++.h>
using namespace std;

map<string, int> cnt;
map<string, set<string>> mp;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    for(string s:report) {
        int m = s.find(' ');
        string from = s.substr(0, m);
        string to = s.substr(m);
        
        if(mp[from].find(to) == mp[from].end()) {
            cnt[to]++;
            mp[from].insert(to);
        }
    }
    
    for(string s:id_list) {
        int res = 0;
        
        for(string str:mp[s]) {
            if(cnt[str] >= k) {
                res++;
            }
        }
        
        answer.push_back(res);
    }
    
    return answer;
}