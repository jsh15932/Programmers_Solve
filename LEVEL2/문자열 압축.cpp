#include<string>
using namespace std;
 
int solution(string s) {
    int answer = s.size();
    int n = s.size() / 2;
 
    for (int i = 1; i <= n; i++) {
        string res = "";
        string tmp = s.substr(0, i);
        int cnt = 1;
 
        for (int j = i; j <= s.size(); j += i) {
            if (tmp == s.substr(j, i)) {
                cnt += 1;
            }
            
            else {
                if (cnt == 1) {
                    res += tmp;
                }
                
                else {
                    res += (to_string(cnt) + tmp);
                }
 
                tmp = s.substr(j, i);
                cnt = 1;
            }
        }
 
        if ((s.size() % i) != 0) {
            res += s.substr((s.size() / i) * i);
        }
 
        if (answer > res.size()) {
            answer = res.size();
        }
    }
 
    return answer;
}
