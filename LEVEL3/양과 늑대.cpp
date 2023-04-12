#include<bits/stdc++.h>
using namespace std;

int x, y = 0;
int answer = 1;

void dfs(int cur, int x, int y, vector<int> nextN, vector<int> info, vector<vector<int>> vc) {
    int chk = info[cur];
    
    if(chk == 1) {
        x++;
    }
    
    else {
        y++;
    }
    
    if(x >= y) {
        return;
    }
    
    answer = max(answer, y);
    
    for(int i = 0; i < nextN.size(); i++) {
        vector<int> next = nextN;
        next.erase(next.begin() + i);
        for(int j = 0; j < vc[nextN[i]].size(); j++) {
            next.push_back(vc[nextN[i]][j]);
        }
        
        dfs(nextN[i], x, y, next, info, vc);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    vector<vector<int>> vc(info.size());
    vector<int> nextN;
    
    for(int i = 0; i < edges.size(); i++) {
        vc[edges[i][0]].push_back(edges[i][1]);
    }
    
    for(int i = 0; i < vc[0].size(); i++) {
        nextN.push_back(vc[0][i]);
    }
    
    dfs(0, 0, 0, nextN, info, vc);
    
    return answer;
}