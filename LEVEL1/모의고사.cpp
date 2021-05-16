#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int a[5] = {1, 2, 3, 4, 5};
int b[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int c[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
int ans_a = 0, ans_b = 0, ans_c = 0;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> vc(3);
    
    for(int i = 0; i < answers.size(); i++) {
        if(a[i % 5] == answers[i]) {
            vc[0]++;
        }
        
        if(b[i % 8] == answers[i]) {
            vc[1]++;
        }
        
        if(c[i % 10] == answers[i]) {
            vc[2]++;
        }
    }
    
    int max_N = max(max(vc[0], vc[1]), vc[2]);
    
    for(int i = 0; i < 3; i++) {
        if(vc[i] == max_N) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}