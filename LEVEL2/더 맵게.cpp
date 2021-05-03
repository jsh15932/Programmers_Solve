#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i : scoville) {
        pq.push(i);
    }
    
    while(pq.top() <= K) {
        if(pq.size() == 1) {
            return -1;
        }
        
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        x += (y * 2);
        
        pq.push(x);
        answer++;
    }
    
    return answer;
}