#include<bits/stdc++.h>
using namespace std;

long long solve(int n) {
    if(n == 1) {
        return 1;
    }
    
    else {
        return n * solve(n - 1);
    }
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> vc;
    long long m, cur;
    
    for(int i = 1; i <= n; i++) {
        vc.push_back(i);
    }
    
    while(true) {
        if(n == 0) {
            break;
        }
        
        m = solve(n) / n;
        cur = int((k - 1) / m);
        answer.push_back(vc[cur]);
        vc.erase(vc.begin() + cur);
        n--;
        k %= m;
        
        if(k == 0) {
            k = m;
        }
    }
    
    return answer;
}