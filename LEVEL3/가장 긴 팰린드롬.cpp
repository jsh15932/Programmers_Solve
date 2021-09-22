#include<bits/stdc++.h>
using namespace std;

int solution(string s)
{
    int answer = 1;
    s.push_back(1);
    
    for(int i = 1; i < s.size(); i++) {
        int left = i - 1, right = i + 1;
        int cnt1 = 0, cnt2 = 1;
        bool chk1 = false, chk2 = false;
        
        while(left >= 0 && right < s.size()) {
            if(s[left] == s[right - 1]) {
                cnt1 += 2;
            }
            
            else {
                chk1 = true;
            }
            
            if(s[left--] == s[right++]) {
                cnt2 += 2;
            }
            
            else {
                chk2 = true;
            }
            
            if(chk1 && chk2) {
                break;
            }
        }
        
        int res;
        
        if(cnt1 > cnt2) {
            res = cnt1;
        }
        
        else {
            res = cnt2;
        }
        
        if(res > answer) {
            answer = res;
        }
    }

    return answer;
}