#include<bits/stdc++.h>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int w = words.size();
    int b = begin.size();
    vector<int> chk(w, 0);
    queue<pair<string, int>> que;
    int d;
    
    que.push({ begin, 0 });
    
    while(!que.empty()) {
        string start = que.front().first;
        int cnt = que.front().second;
        
        que.pop();
        
        for(int i = 0; i < w; i++) {
            d = 0;
            
            if(chk[i] != 0) {
                continue;
            }
            
            for(int j = 0; j < b; j++) {
                if(start[j] != words[i][j]) {
                    d++;
                }
            }
            
            if(d == 1) {
                if(words[i] == target) {
                    return cnt + 1;
                }
                
                chk[i] = 1;
                que.push({ words[i], cnt + 1});
            }
        }
    }
    
    return answer;
}