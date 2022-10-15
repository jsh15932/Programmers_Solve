#include<bits/stdc++.h>
using namespace std;

int arr[101];

bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int getParent(int node) {
    if(arr[node] == node) {
        return node;
    }
    
    return arr[node] = getParent(arr[node]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for(int i = 0; i < n; i++) {
        arr[i] = i;
    }
    
    sort(costs.begin(), costs.end(), cmp);
    
    for(int i = 0; i < costs.size(); i++) {
        int start = getParent(costs[i][0]);
        int end = getParent(costs[i][1]);
        int cost = costs[i][2];
        
        if(start == end) {
            continue;
        }
        
        answer += cost;
        arr[end] = start;
    }
    
    return answer;
}