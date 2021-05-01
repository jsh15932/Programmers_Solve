#include<string>
using namespace std;

int solution(string name) {
    int answer = 0;
    int p = 0;
    string cmp;
    
    for(int i = 0; i < name.size(); i++) {
        cmp += "A";
    }
    
    while(cmp != name) {
        int next = 0;
        int left = 0;
        int right = 0;
        
        for(int i = 0; i < name.size(); i++) {
            if(i + p < name.size()) {
                right = i + p;
            }
            
            else {
                right = i + p - name.size();
            }
            
            if(i <= p) {
                left = p - i;
            }
            
            else {
                left = p - i + name.size();
            }
            
            if(cmp[right] != name[right]) {
                next = right;
            }
            
            else if(cmp[left] != name[left]) {
                next = left;
            }
            
            else {
                continue;
            }
            
            answer += i;
            answer += min(name[next] - 'A', 'Z' - name[next] + 1);
            cmp[next] = name[next];
            
            break;
        }
        
        p = next;
    }
    
    return answer;
}