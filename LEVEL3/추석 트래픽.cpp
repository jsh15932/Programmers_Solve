#include<string>
#include<vector>
using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    vector<int> start, end;
    
    for(int i = 0; i < lines.size(); i++) {
        string h, m, s, ms;
        int hour, min, sec, res;
        
        lines[i].pop_back();
        h = lines[i].substr(11, 2);
        m = lines[i].substr(14, 2);
        s = lines[i].substr(17, 2);
        ms = lines[i].substr(20, 3);
        res = stof(lines[i].substr(24, 5)) * 1000;
        
        hour = stoi(h) * 3600 * 1000;
        min = stoi(m) * 60 * 1000;
        sec = stoi(s) * 1000 + stoi(ms);
        
        start.push_back(hour + min + sec - res + 1);
        end.push_back(hour + min + sec);
    }
    
    for(int i = 0; i < lines.size(); i++) {
        int endTime = end[i] + 1000;
        int cnt = 0;
        
        for(int j = i; j < lines.size(); j++) {
            if(start[j] < endTime) {
                cnt++;
            }
        }
        
        if(cnt > answer) {
            answer = cnt;
        }
    }
    
    return answer;
}