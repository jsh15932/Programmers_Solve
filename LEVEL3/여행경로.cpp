#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int max_N = 0;

void DFS(string start, vector<vector<string>>& tickets, vector<bool>& visit, vector<string>& answer, vector<string>& tmp, int cnt) {
    tmp.push_back(start);
    
    if(cnt > max_N) {
        max_N = cnt;
        answer = tmp;
    }
    
    for(int i = 0; i < tickets.size(); i++) {
        if(start == tickets[i][0] && !visit[i]) {
            visit[i] = true;
            DFS(tickets[i][1], tickets, visit, answer, tmp, cnt + 1);
            visit[i] = false;
        }
    }
    
    tmp.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer, tmp;
    vector<bool> visit(tickets.size(), false);
    int cnt = 0;
    
    sort(tickets.begin(), tickets.end());
    
    DFS("ICN", tickets, visit, answer, tmp, cnt);
    
    return answer;
}