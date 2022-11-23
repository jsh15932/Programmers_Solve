#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long sum1 = 0, sum2 = 0;
    queue<int> que1, que2;
    
    for(int n : queue1) {
        sum1 += n;
        que1.push(n);
    }
    
    for(int n : queue2) {
        sum2 += n;
        que2.push(n);
    }
    
    int idx1 = 0, idx2 = 0;
    int maxN = queue1.size() + queue2.size();
    
    while(idx1 < maxN && idx2 < maxN) {
        if(sum1 == sum2) {
            return answer;
        }
        
        if(sum1 < sum2) {
           int k = que2.front(); 
           que2.pop();
           que1.push(k);
            
           sum1 += k;
           sum2 -= k;
            
           idx2++;
        }
        
        else {
           int k = que1.front();
           que1.pop();
           que2.push(k);
            
           sum1 -= k;
           sum2 += k;
            
           idx1++;
        }
        
        answer++;
    }
    
    return -1;
}