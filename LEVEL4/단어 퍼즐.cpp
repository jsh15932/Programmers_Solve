#include<bits/stdc++.h>
using namespace std;
#define INF 1e9

int solution(vector<string> strs, string t)
{
    int answer = -1;
    int arr[20001];
    bool chk = true;
    
    for(int i = 1; i <= t.length(); i++) {
        arr[i] = INF;
    }
    
    for(int i = 1; i <= t.length(); i++) {
        for(int j = 0; j < strs.size(); j++) {
            int prevIdx = i - strs[j].length();
            
            if(prevIdx < 0) {
                continue;   
            }
            
            chk = true;

            for(int k = 0; k < strs[j].length(); k++) {
                if(t[prevIdx + k] != strs[j][k]) {
                    chk = false;
                    break;
                }
            }

            if(chk) {
                arr[i] = min(arr[i], arr[prevIdx] + 1);
            }
        }
    }
    
    answer = arr[t.length()];
    
    if(answer == INF) {
        return -1;
    }

    return answer;
}