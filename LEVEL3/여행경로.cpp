#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool dfs(vector<vector<string>> &tickets, vector<string> &vc, vector<bool> &visited, string next) {
    vc.push_back(next);
    
    if(vc.size() == tickets.size() + 1) {
        return true;
    }
    
    for(int i = 0; i < tickets.size(); i++) {
        if(!visited[i] && tickets[i][0] == next) {
            visited[i] = true;
            
            if(dfs(tickets, vc, visited, tickets[i][1])) {
                return true;
            }
            
            visited[i] = false;
        }
    }
    
    vc.pop_back();
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end());
    
    for(int i = 0; i < tickets.size(); i++) {
        vector<bool> visited(tickets.size(), false);
        vector<string> vc;
        
        if(tickets[i][0] == "ICN") {
            visited[i] = true;
            vc.push_back("ICN");
            
            if(dfs(tickets, vc, visited, tickets[i][1])) {
                answer = vc;
                
                break;
            }
        }
    }
    
    return answer;
}