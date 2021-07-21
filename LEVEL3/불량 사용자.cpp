#include<string>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int user_len, banned_len;
bool chk[8];
set<string> s;

void solve(int idx, string res, vector<string> user_id, vector<string> banned_id) {
    if(idx == banned_len) {
        sort(res.begin(), res.end());
        s.insert(res);
        
        return;
    }
    
    string b_id = banned_id[idx];
    int b_len = b_id.size();
    
    for(int i = 0; i < user_len; i++) {
        string u_id = user_id[i];
        
        if(u_id.size() != b_len) {
            continue;
        }
        
        if(chk[i]) {
            continue;
        }
        
        bool flag = true;
        
        for(int j = 0; j < b_len; j++) {
            if(b_id[j] == '*') {
                continue;
            }
            
            if(u_id[j] != b_id[j]) {
                flag = false;
                
                break;
            }
        }
        
        if(flag) {
            chk[i] = true;
            solve(idx + 1, res + to_string(i), user_id, banned_id);
            
            chk[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    user_len = user_id.size();
    banned_len = banned_id.size();
    
    solve(0, "", user_id, banned_id);
    answer = s.size();
    
    return answer;
}