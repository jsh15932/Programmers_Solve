#include<string>
#include<vector>
using namespace std;

bool chk(string s) {
    int sum = 0;
    
    for(int i = 0; i < s.length(); i++) {
        if(s.at(i) == '(') {
            sum++;
        }
        
        else if(s.at(i) == ')') {
            sum--;
        }
        
        if(sum < 0) {
            return false;
        }
    }
    
    return true;
}

string solve(string s) {
    string answer = "";
    
    if(s == "") {
        return "";
    }
    
    string u, v;
    int idx = 0, left = 0, right = 0;
    
    for(idx = 0; idx < s.length(); idx++) {
        if(s.at(idx) == '(') {
            left++;
        }
        
        else if(s.at(idx) == ')') {
            right++;
        }
        
        if(left == right) {
            u = s.substr(0, idx + 1);
            v = s.substr(idx + 1);
            
            break;
        }
    }
    
    if(chk(u)) {
        return u + solve(v);
    }
    
    else {
        string tmp = '(' + solve(v) + ')';
        u = u.substr(1, u.length() - 2);
        
        for(int i = 0; i < u.length(); i++) {
            if(u.at(i) == '(') {
                tmp = tmp + ')';
            }
            
            else {
                tmp = tmp + '(';
            }
        }
        
        return tmp;
    }
}

string solution(string p) {
    return solve(p);
}