#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<string, int>> que;
    vector<int> chk(words.size(), 0);
    
    que.push({ begin, 0 });
    
    while(!que.empty()) {
        string start = que.front().first;
        int cnt = que.front().second;
        
        que.pop();
        
        for(int i = 0; i < words.size(); i++) {
            int k = 0;
            
            if(chk[i] != 0) {
                continue;
            }
            
            for(int j = 0; j < words[i].size(); j++) {
                if(start[j] != words[i][j]) {
                    k++;
                }
            }
            
            if(k == 1) {
                if(words[i] == target) {
                    return cnt + 1;
                }
                
                chk[i] = true;
                que.push({ words[i], cnt + 1 });
            }
        }
    }
    
    return answer;
}