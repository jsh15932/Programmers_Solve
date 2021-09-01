#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int toNum(string s) {
    string h = s.substr(0, 2);
    string m = s.substr(3, 2);
    
    int hour = stoi(h) * 60;
    int min = stoi(m);
    
    return hour + min;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> vc;
    
    for(int i = 0; i < timetable.size(); i++) {
        string tmp = timetable[i];
        int k = toNum(tmp);
        vc.push_back(k);
    }
    
    sort(vc.begin(), vc.end());
    
    int start = 540;
    int idx = 0;
    int res = 0;
    
    for(int i = 0; i < n; i++) {
        int maxN = m;
        
        for(int i = idx; i < vc.size(); i++) {
            if(vc[i] <= start) {
                idx++;
                maxN--;
                
                if(maxN == 0) {
                    break;
                }
            }
        }
        
        if(i == n - 1) {
            if(maxN == 0) {
                res = vc[idx - 1] - 1;
            }
            
            else {
                res = start;
            }
        }
        
        start += t;
        
        if(start >= (60 * 24)) {
            break;
        }
    }
    
    string tmp = "";
    int hour = res / 60;
    
    if(hour < 10) {
        tmp += "0" + to_string(hour);
    }
    
    else {
        tmp += to_string(hour);
    }
    
    tmp += ":";
    int min = res % 60;
    
    if(min < 10) {
        tmp += "0" + to_string(min);
    }
    
    else {
        tmp += to_string(min);
    }
    
    answer = tmp;
    
    return answer;
}