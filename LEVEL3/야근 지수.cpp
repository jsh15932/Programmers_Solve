#include<bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    
    for(int i = 0; i < works.size(); i++) {
        pq.push(works[i]);
    }
    
    while(n--) {
        if(pq.empty()) {
            break;
        }
        
        int top = pq.top();
        pq.pop();
        top--;
        
        if(top > 0) {
            pq.push(top);
        }
    }
    
    while(!pq.empty()) {
        long long tmp = pow(pq.top(), 2);
        pq.pop();
        answer += tmp;
    }
    
    return answer;
}