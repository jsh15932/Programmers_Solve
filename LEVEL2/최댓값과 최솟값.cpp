#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(string a, string b) {
    int numA = stoi(a);
    int numB = stoi(b);
    
    if(numA <= numB) {
        return true;
    }
    
    return false;
}

string solution(string s) {
    vector<string> vc;
    string tmp = "";
    string answer = "";
    
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') {
            vc.push_back(tmp);
            tmp = "";
            continue;
        }
        
        else {
            tmp += s[i];
        }
    }
    
    vc.push_back(tmp);
    sort(vc.begin(), vc.end(), cmp);
    
    answer += vc[0];
    answer += " ";
    answer += vc[vc.size() - 1];
    
    return answer;
}