#include<bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>> chk(n + 1, vector<bool>(n + 1, false));
    
    for(auto i : results) {
        int win = i[0];
        int lose = i[1];
        chk[win][lose] = true;
    }
    
    for(int via = 1; via <= n; via++) {
        for(int from = 1; from <= n; from++) {
            for(int to = 1; to <= n; to++) {
                if(chk[from][via] && chk[via][to]) {
                    chk[from][to] = true;
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                continue;
            }
            
            if(chk[i][j] || chk[j][i]) {
                cnt++;
            }
        }
        
        if(cnt == n - 1) {
            answer++;
        }
    }
    
    return answer;
}