#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    queue<pair<int, int>> que;
    priority_queue<int> pq;
    
    for(int i = 0; i < priorities.size(); i++) {
        que.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]);
    }
    
    while(!que.empty()) {
        if(que.front().second == pq.top()) {
            if(que.front().first == location) {
                return answer;
            }
            
            else {
                answer++;
                que.pop();
                pq.pop();
            }
        }
        
        else {
            que.push(que.front());
            que.pop();
        }
    }
    
    return answer;
}