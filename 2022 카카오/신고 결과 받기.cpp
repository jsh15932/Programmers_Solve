#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int len = id_list.size();
    vector<int> answer(len);
    unordered_map<string, unordered_set<string>> mp1;
    unordered_map<string, unordered_set<string>> mp2;
    
    for(string s : report) {
        int blank = s.find(' ');
        string from = s.substr(0, blank);
        string to = s.substr(blank + 1);
        mp1[from].insert(to);
        mp2[to].insert(from);
    }
    
    for(int i = 0; i < len; i++) {
        string from = id_list[i];
        auto it = mp1.find(from);
        
        if(it == mp1.end()) {
            continue;
        }
        
        for(string s : it -> second) {
            if(mp2[s].size() >= k) {
                answer[i]++;
            }
        }
    }
    
    return answer;
}