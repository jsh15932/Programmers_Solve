#include<string>
#include<vector>
using namespace std;

void dfs(int node, vector<vector<int>> &vc, vector<bool> &visited, int n) {
    visited[node] = true;
    
    for(int i = 0; i < n; i++) {
        if(!visited[i] && vc[node][i]) {
            dfs(i, vc, visited, n);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            answer++;
            
            dfs(i, computers, visited, n);
        }
    }
    
    return answer;
}