#include<bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int max = 0;
    queue<int> que;
    bool visited[20001] = {false, };
    bool chk[20001][20001] = {false, };
    int d[20001] = {0, };
    
    sort(edge.begin(), edge.end());
    
    for(int i = 0; i < edge.size(); i++) {
        chk[edge[i][0]][edge[i][1]] = true;
        chk[edge[i][1]][edge[i][0]] = true;
    }
    
    que.push(1);
    visited[1] = true;
    
    while(!que.empty()) {
        int cur = que.front();
        que.pop();
        
        for(int i = 2; i <= n; i++) {
            if(chk[cur][i] && !visited[i]) {
                que.push(i);
                visited[i] = true;
                d[i] = d[cur] + 1;
                
                if(d[i] > max) {
                    max = d[i];
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        if(max == d[i]) {
            answer++;
        }
    }
    
    return answer;
}