#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(const pair <int, int> &a, const pair <int, int> &b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    
    else {
        return a.second < b.second;
    }
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int start = 0;
    int t = 0;
    vector <pair <int, int>> vc;
    
    for(int i = 0; i < jobs.size(); i++) {
        vc.push_back(make_pair(jobs[i][0], jobs[i][1]));
    }
    
    sort(vc.begin(), vc.end(), cmp);
    
    while(!vc.empty()) {
        for(int i = 0; i < vc.size(); i++) {
            if(vc[i].first <= start) {
                start += vc[i].second;
                t += start - vc[i].first;
                vc.erase(vc.begin() + i);
                
                break;
            }
            
            if(i == vc.size() - 1) {
                start++;
            }
        }
    }
    
    answer = t / jobs.size();
    
    return answer;
}