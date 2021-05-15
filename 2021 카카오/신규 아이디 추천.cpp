#include<string>
#include<vector>
using namespace std;

bool chk_1(char c) {
    return 'a' <= c && c <= 'z';
}

bool chk_2(char c) {
    return 'A' <= c && c <= 'Z';
}

bool chk_3(char c) {
    return '0' <= c && c <= '9';
}

string solution(string new_id) {
    string answer = "";
    string s = new_id;
    
    for(int i = 0; i < s.length(); i++) {
        if(chk_2(s[i])) {
            s[i] = s[i] - 'A' + 'a';
        }
    }
    
    string s2;
    
    for(int i = 0; i < s.length(); i++) {
        if(chk_1(s[i]) || chk_3(s[i]) || s[i] == '-' || s[i] == '_' || s[i] == '.') {
            s2 += s[i];
        }
    }
    
    bool chk_4 = false;
    
    for(int i = 0; i < s2.length(); i++) {
        if(s2[i] == '.' && chk_4) {
            continue;
        }
        
        answer += s2[i];
        chk_4 = s2[i] == '.';
    }
    
    if(!answer.empty() && answer.front() == '.') {
        answer = answer.substr(1);
    }
    
    if(!answer.empty() && answer.back() == '.') {
        answer.pop_back();
    }
    
    if(answer.empty()) {
        answer += 'a';
    }
    
    if(answer.size() >= 16) {
        answer = answer.substr(0, 15);
        
        if(answer.back() == '.') {
            answer.pop_back();
        }
    }
    
    if(answer.size() == 1) {
        answer = answer + answer + answer;
    }
    
    else if(answer.size() == 2) {
        answer += answer.back();
    }
    
    return answer;
}