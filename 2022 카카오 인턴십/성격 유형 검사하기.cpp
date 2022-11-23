#include<bits/stdc++.h>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> mp;
    
    for(int i = 0; i < survey.size(); i++) {
        if(choices[i] > 4) {
            mp[survey[i][1]] += choices[i] - 4;
        }
        
        else if(choices[i] < 4) {
            mp[survey[i][0]] += 4 - choices[i];
        }
    }
    
    answer += mp['R'] >= mp['T'] ? "R" : "T";
    answer += mp['C'] >= mp['F'] ? "C" : "F";
    answer += mp['J'] >= mp['M'] ? "J" : "M";
    answer += mp['A'] >= mp['N'] ? "A" : "N";
    
    return answer;
}