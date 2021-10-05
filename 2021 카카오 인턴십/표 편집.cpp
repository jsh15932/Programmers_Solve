#include<bits/stdc++.h>
using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'X');
    set<int> tb;
    stack<int> st;
    
    for(int i = 0; i < n; i++) {
        tb.insert(i);
    }
    
    auto cur = tb.find(k);
    
    for(string s : cmd) {
        if(s[0] == 'U' || s[0] == 'D') {
            int num = stoi(s.substr(2));
            
            if(s[0] == 'U') {
                while(num--) {
                    cur = prev(cur);
                }
            }
            
            else {
                while(num--) {
                    cur = next(cur);
                }
            }
        }
        
        else if(s[0] == 'C') {
            st.push(*cur);
            cur = tb.erase(cur);
            
            if(cur == tb.end()) {
                cur = prev(cur);
            }
        }
        
        else if(s[0] == 'Z') {
            tb.insert(st.top());
            st.pop();
        }
        
        else {
            return "";
        }
    }
    
    for(int i : tb) {
        answer[i] = 'O';
    }
    
    return answer;
}