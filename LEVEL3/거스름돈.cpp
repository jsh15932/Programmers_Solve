#include<bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    int dp[100001];
    dp[0] = 1;
    sort(money.begin(), money.end());
    
    for(auto c : money) {
        for(int i = 1; i <= n; i++) {
            if(i < c) {
                continue;
            }
            
            dp[i] = (dp[i] + dp[i - c]) % 1000000007;
        }
    }
    
    answer = dp[n];
    
    return answer;
}