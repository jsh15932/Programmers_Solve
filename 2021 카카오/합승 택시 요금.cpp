#include<bits/stdc++.h>
using namespace std;

int arr[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                arr[i][j] = 0;
            }
            
            else {
                arr[i][j] = 1000000;
            }
        }
    }
    
    for(auto i : fares) {
        arr[i[0]][i[1]] = arr[i[1]][i[0]] = i[2];
    }
    
    for(int via = 1; via <= n; via++) {
        for(int from = 1; from <= n; from++) {
            for(int to = 1; to <= n; to++) {
                arr[from][to] = min(arr[from][to], arr[from][via] + arr[via][to]);
            }
        }
    }
    
    answer = 1e9;
    
    for(int i = 1; i <= n; i++) {
        answer = min(answer, arr[s][i] + arr[i][a] + arr[i][b]);
    }
    
    return answer;
}