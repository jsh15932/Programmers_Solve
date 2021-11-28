#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, sum = 0, idx = 0;
    queue<int> que;
    
    while(1) {
        if(idx == truck_weights.size()) {
            answer += bridge_length;
            
            break;
        }
        
        answer++;
        
        int tmp = truck_weights[idx];
        
        if(que.size() == bridge_length) {
            sum -= que.front();
            que.pop();
        }
        
        if(sum + tmp <= weight) {
            que.push(tmp);
            sum += tmp;
            idx++;
        }
        
        else {
            que.push(0);
        }
    }
    
    return answer;
}