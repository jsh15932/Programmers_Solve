#include<string>
#include<vector>
#include<queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> vc;
    queue<int> que;
    
    for(int i = 0; i < progresses.size(); i++) {
        int d = (100 - progresses[i]) / speeds[i];
        
        if((progresses[i] + d * speeds[i]) != 100) {
            d++;
        }
        
        vc.push_back(d);
    }
    
    que.push(vc[0]);
    
    for(int i = 1; i < vc.size(); i++) {
        if(que.front() >= vc[i]) {
            que.push(vc[i]);
        }
        
        else {
            answer.push_back(que.size());
            
            while(!que.empty()) {
                que.pop();
            }
            
            que.push(vc[i]);
        }
    }
    
    if(!que.empty()) {
        answer.push_back(que.size());
    }
    
    return answer;
}