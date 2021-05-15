#include<string>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

int arr[27];
vector<string> dp[27][21];
map<string, int> mp;

void find(string s1, int idx, string s2) {
    if(s2.size() > 1) {
        mp[s2]++;
        arr[s2.size()] = max(arr[s2.size()], mp[s2]);
        dp[s2.size()][mp[s2]].push_back(s2);
    }
    
    for(int i = idx + 1; i < s1.size(); i++) {
        s2.push_back(s1[i]);
        find(s1, i, s2);
        s2.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(string &s : orders) {
        sort(s.begin(), s.end());
        find(s, -1, "");
    }
    
    for(int i : course) {
        if(arr[i] > 1) {
            for(string s: dp[i][arr[i]]) {
                answer.push_back(s);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}