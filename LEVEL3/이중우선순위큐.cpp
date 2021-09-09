#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    priority_queue<int, vector<int>, greater<int>> pq1;
    priority_queue<int, vector<int>> pq2;
    int cnt = 0;
    
    for(string s : operations) {
        if(cnt == 0) {
            while(!pq1.empty()) {
                pq1.pop();
            }
            
            while(!pq2.empty()) {
                pq2.pop();
            }
        }
        
        if(s[0] == 'I') {
            pq2.push(stoi(s.substr(2)));
            pq1.push(stoi(s.substr(2)));
            cnt++;
        }
        
        else {
            if(cnt == 0) {
                continue;
            }
            
            if(s[2] == '1') {
                pq2.pop();
                cnt--;
            }
            
            else {
                pq1.pop();
                cnt--;
            }
        }
    }
    
    if(cnt > 0) {
        answer[0] = pq2.top();
        answer[1] = pq1.top();
    }
    
    return answer;
}