#include<bits/stdc++.h>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if(n > s) {
        answer.push_back(-1);
        
        return answer;
    }
    
    int k = s / n;
    int r = s % n;
    int num = 0;
    
    if(s % n != 0) {
        num = 1;
    }
    
    for(int i = 0; i < n; i++) {
        if(i >= n - r) {
            answer.push_back(k + 1);
        }
        
        else {
            answer.push_back(k);
        }
    }
    
    return answer;
}