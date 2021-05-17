#include<string>
#include<vector>
using namespace std;

int solution(string s) {
    int answer = 0, res = 0;
    bool chk = true;
    
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '-') {
            chk = false;
        }
        
        else if(s[i] != '+') {
            res = res * 10 + (s[i] - '0');
        }
    }
    
    if(chk) {
        answer = res;
    }
    
    else {
        answer = res * -1;
    }
    
    return answer;
}