#include<bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> data) {
    int answer = 0;
    sort(data.begin(), data.end());

    for(int i = 0; i < n; i++) {
        int x = data[i][0];
        int y = data[i][1];

        for(int j = i + 1; j < n; j++) {
            int nextX = data[j][0];
            int nextY = data[j][1];
            bool chk = true;

            if(x == nextX || y == nextY) {
                continue;
            }

            for(int k = i + 1; k < j; k++) {
                int endX = data[k][0];
                int endY = data[k][1];
                
                if((endX > x && endX < nextX) && (endY > min(y, nextY) && endY < max(y, nextY))) {
                    chk = false;
                    break;
                } 
            }

            if(chk == true) {
                answer++;
            }
        }
    }

    return answer;
}