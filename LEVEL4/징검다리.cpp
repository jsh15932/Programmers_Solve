#include<bits/stdc++.h>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    int left = 0, right = distance;
    
    while(left <= right) {
        int mid = (left + right) / 2;
        int idx = -1, cnt = 0;
        
        for(int i = 0; i < rocks.size(); i++) {
            int d;
            
            if(i == 0) {
                d = rocks[i];
            }
            
            else {
                if(i == rocks.size()) {
                    d = distance - rocks[rocks.size() - 1];
                }
                    
                else {
                    d = rocks[i] - rocks[idx];
                }
            }

            if(mid > d) {
                cnt++;
            }

            else {
                idx = i;
            }
        }
        
        if(cnt > n) {
            right = mid - 1;
        }
        
        else {
            left = mid + 1;
            answer = max(answer, mid);
        }
    }
    
    return answer;
}