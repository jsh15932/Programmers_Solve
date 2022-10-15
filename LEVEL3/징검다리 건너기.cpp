#include<bits/stdc++.h>
using namespace std;
#define maxN 200000000

int solution(vector<int> stones, int k) {
    int answer = 0;
    int left = maxN;
    int right = 1;

    for(int i = 0; i < stones.size(); i++) {
        if(i >= right) {
            right = i;
        }
    }

    for(int i = 0; i < stones.size(); i++) {
        if(i <= left) {
            left = i;
        }
    }

    int mid = 0;

    while(left <= right) {
        mid = (left + right) / 2;
        int cnt = 0;
        int maxCnt = 0;
        vector<int> vc(stones);
        
        for(int i = 0; i < vc.size(); i++) {
            if(vc[i] < mid) {
                cnt++;
            }
            else {
                cnt = 0;
            }
            maxCnt = max(maxCnt, cnt);
        }

        if(maxCnt >= k) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
            answer = max(answer, mid);
        }
    }
    
    return answer;
}