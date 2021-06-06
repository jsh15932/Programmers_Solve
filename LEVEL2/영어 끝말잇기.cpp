#include<string>
#include<vector>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int chk = 0;
    int a = 0, b = 0;
    
    for(int i = 1; i < words.size(); i++) {
        string s1 = words[i - 1];
        string s2 = words[i];
        
        for(int j = 0; j < i; j++) {
            if(words[j] == words[i]) {
                chk = 1;
                
                break;
            }
        }
        
        if(s1[s1.length() - 1] != s2[0]) {
            chk = 1;
        }
        
        if(chk) {
            a = (i % n) + 1;
            b = (i / n) + 1;
            answer.push_back(a);
            answer.push_back(b);
            
            return answer;
        }
    }
    
    answer.push_back(0);
    answer.push_back(0);
    
    return answer;
}