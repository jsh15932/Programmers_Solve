#include<bits/stdc++.h>
using namespace std;

long long answer = 0;

void solve(vector<vector<int>> &vc, vector<long long> &res, int cur, int parent) {
    for(int i = 0; i < vc[cur].size(); i++) {
        if(vc[cur][i] != parent) {
            solve(vc, res, vc[cur][i], cur);
        }
    }
    
    res[parent] += res[cur];
    answer += abs(res[cur]);
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    vector<long long> res(a.size());
    vector<vector<int>> vc(a.size());
    
    for(int i = 0; i < a.size(); i++) {
        res[i] = a[i];
    }
    
    for(int i = 0; i < edges.size(); i++) {
        vc[edges[i][0]].push_back(edges[i][1]);
        vc[edges[i][1]].push_back(edges[i][0]);
    }
    
    solve(vc, res, 0, 0);
    
    if(res[0] == 0) {
        return answer;
    }
    
    return -1;
}