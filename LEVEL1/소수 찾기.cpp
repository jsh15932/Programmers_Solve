#include<string>
#include<vector>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> vc(n + 1);
    
    for(int i = 2; i <= n; i++) {
        vc[i] = i;
    }
    
    for(int i = 2; i <= n; i++) {
        if(vc[i] == 0) {
            continue;
        }
        
        for(int j = i * 2; j <= n; j += i) {
            vc[j] = 0;
        }
    }
    
    for(int i = 0; i < vc.size(); i++) {
        if(vc[i] != 0) {
            answer++;
        }
    }
    
    return answer;
}