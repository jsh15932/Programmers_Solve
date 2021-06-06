#include<string>
#include<vector>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    int zero = 0;
    int cnt = 0;
    
    while(s != "1") {
        string tmp = "";
        int size = 0;
        cnt++;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') {
                zero++;
            }
            
            else {
                tmp += "1";
            }
        }
        
        int num = tmp.size();
        s = "";
        
        while(num > 0) {
            s += to_string(num % 2);
            num /= 2;
        }
    }
    
    answer[0] = cnt;
    answer[1] = zero;
    
    return answer;
}