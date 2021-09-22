#include<bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0, start = 1, idx = 0;
    
    while(start <= n) {
        if(start >= stations[idx] - w && start <= stations[idx] + w) {
            start = stations[idx] + w;
            idx++;
        }
        
        else {
            start += w * 2;
            answer++;
        }
        
        start++;
    }

    return answer;
}