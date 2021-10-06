#include<bits/stdc++.h>
using namespace std;

vector<string> user;
vector<string> banned;
bool visited[10];
set<string> s;

void solve(int idx) {
    if(idx == banned.size()) {
        string tmp = "";
        
        for(int i = 0; i < user.size(); i++) {
            if(visited[i]) {
                tmp += user[i];
            }
        }
        
        s.insert(tmp);
        
        return;
    }
    
    for(int i = 0; i < user.size(); i++) {
        bool chk = true;
        
        if(visited[i]) {
            continue;
        }
        
        if(user[i].length() != banned[idx].length()) {
            continue;
        }
        
        for(int j = 0; j < user[i].length(); j++) {
            if(banned[idx][j] == '*') {
                continue;
            }
            
            if(banned[idx][j] != user[i][j]) {
                chk = false;
                
                break;
            }
        }
        
        if(chk) {
            visited[i] = true;
            solve(idx + 1);
            visited[i] = false;
        }
    }
    
    return;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    user = user_id;
    banned = banned_id;
    
    solve(0);
    
    answer = s.size();
    
    return answer;
}