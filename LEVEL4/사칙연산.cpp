#include<bits/stdc++.h>
using namespace std;
#define INF 9e8

int dp[101][101][2];
vector<string> vc;

int solve(int left, int right, int k) {
    int& res = dp[left][right][k];
    
    if(res != -1) {
        return res;
    }
    
    if(k) {
        res = -INF;
        
        for(int i = left; i <= right; i++) {
            int leftN, rightN;
            
            if(left > i - 1) {
                leftN = stoi(vc[left * 2]);
            }
            
            else {
                leftN = solve(left, i - 1, 1);
            }
            
            if(i + 1 > right) {
                rightN = stoi(vc[right * 2 + 2]);
            }
            
            else if(vc[i * 2 + 1] == "+") {
                rightN = solve(i + 1, right, 1);
            }
            
            else {
                rightN = solve(i + 1, right, 0);
            }
            
            if(vc[i * 2 + 1] == "+") {
                res = max(leftN + rightN, res);
            }
            
            else {
                res = max(leftN - rightN, res);
            }
        }
    }
    
    else {
        res = INF;
        
        for(int i = left; i <= right; i++) {
            int leftN, rightN;
            
            if(left > i - 1) {
                leftN = stoi(vc[left * 2]);
            }
            
            else {
                leftN = solve(left, i - 1, 0);
            }
            
            if(i + 1 > right) {
                rightN = stoi(vc[right * 2 + 2]);
            }
            
            else if(vc[i * 2 + 1] == "+") {
                rightN = solve(i + 1, right, 0);
            }
            
            else {
                rightN = solve(i + 1, right, 1);
            }
            
            if(vc[i * 2 + 1] == "+") {
                res = min(leftN + rightN, res);
            }
            
            else {
                res = min(leftN - rightN, res);
            }
        }
    }
    
    return res;
}


int solution(vector<string> arr)
{
    memset(dp, -1, sizeof(dp));
    vc = arr;
    
    return solve(0, vc.size() / 2 - 1, 1);
}