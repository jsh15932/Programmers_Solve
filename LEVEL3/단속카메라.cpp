#include<bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int flag = 30001;
    
    sort(routes.begin(), routes.end());
    reverse(routes.begin(), routes.end());
    
    for(int i = 0; i < routes.size(); i++) {
        if(routes[i][1] < flag) {
            flag = routes[i][0];
            answer++;
        }
    }
    
    return answer;
}