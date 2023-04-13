#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2, 0);
    queue<pair<int, int>> que;
    int sum = 0;
    int len = sequence.size() + 1;
    
    for(int i = 0; i < sequence.size(); i++) {
        que.push({
            sequence[i], i
        });
        sum += sequence[i];
        
        while(sum > k) {
            sum -= que.front().first;
            que.pop();
        }
        
        if(sum == k && que.size() < len) {
            len = que.size();
            answer[0] = que.front().second;
            answer[1] = que.back().second;
        }
    }
    
    return answer;
}