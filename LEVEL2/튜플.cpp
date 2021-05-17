#include<string>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> tmp;
    vector<pair<int, vector<int>>> vc;
    int size = s.size();   
    int num = 0;
    
    for(int i = 0; i < size - 1; i++) {
        if(s[i] == '{') {
            continue;
        }
        
        if(s[i] == '}') {
            tmp.push_back(num);
            vc.push_back(make_pair(tmp.size(), tmp));
            num = 0;
            tmp.clear();
        }
        
        else if(s[i] == ',') {
            if(s[i - 1] == '}') {
                continue;
            }
            
            tmp.push_back(num);
            num = 0;
        }
        
        else {
            num *= 10;
            num += (s[i] - '0');
        }
    }
    
    sort(vc.begin(), vc.end());
    
    set<int> res;
    
    for(pair <int, vector<int>> p : vc) {
        for(int num : p.second) {
            if(res.find(num) == res.end()) {
                res.insert(num);
                answer.push_back(num);
            }
        }
    }
    
    return answer;
}