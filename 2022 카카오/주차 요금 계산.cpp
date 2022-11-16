#include<bits/stdc++.h>
using namespace std;

int change(string t) {
    string h = t.substr(0, 2);
    string m = t.substr(3);
    
    return stoi(h) * 60 + stoi(m);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    unordered_map<string, int> mp1;
    map<string, int> mp2;
    
    for(string s : records) {
        string t = s.substr(0, 5);
        string n = s.substr(6, 4);
        string k = s.substr(11);
        
        if(k == "IN") {
            mp1[n] = change(t);
        }
        
        else {
            mp2[n] += change(t) - mp1[n];
            mp1.erase(n);
        }
    }
    
    for(auto i : mp1) {
        mp2[i.first] += ((23 * 60) + 59) - i.second; 
    }
    
    for(auto i : mp2) {
        if(i.second <= fees[0]) {
            answer.push_back(fees[1]);
        }
        
        else {
            int res = fees[1] + (ceil((i.second - fees[0]) / (double)fees[2]) * fees[3]);
            answer.push_back(res);
        }
    }
    
    return answer;
}