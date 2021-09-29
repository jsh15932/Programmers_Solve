#include<bits/stdc++.h>
using namespace std;

int arr[20001];

int solution(vector<string> strs, string t)
{
    int answer = 0;

    for(int i = 0 ; i < t.size(); i++) {
        int idx = i;
        char c = t[i];
        arr[idx] = t.size() + 1;
        
        for(int j = 0; j < strs.size(); j++) {
            bool chk = true;
            int len = strs[j].size() - 1;
            
            if(strs[j][len] == c) {
                for(int k = 0; k <= len; k++) {
                    if(t[idx - k] != strs[j][len - k]) {
                        chk = false;
                        
                        break;
                    }
                }
                
                if(chk) {
                    if(idx - len - 1 == -1) {
                        arr[idx] = 1;
                    }
                    
                    else {
                        if(arr[idx - len - 1] + 1 < arr[idx]) {
                            arr[idx] = arr[idx - len - 1] + 1;
                        }
                    }
                }
            }
        }
    }
    
    answer = arr[t.size() - 1];
    
    if(answer >= t.size() + 1) {
        answer = -1;
    }
    
    return answer;
}