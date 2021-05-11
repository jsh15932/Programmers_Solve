#include<string>
#include<set>
#include<vector>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    set<int> win_num;
    
    for(int i = 0; i < 6; i++) {
        win_num.insert(win_nums[i]);
    }
    
    int k = 0;
    int match = 0;
    
    for(int i = 0; i < 6; i++) {
        if(lottos[i] == 0) {
            k++;
        }
        
        else if(win_num.find(lottos[i]) != win_num.end()) {
            match++;
        }
    }
    
    if(k + match == 1 || k + match == 0) {
        answer.push_back(6);
    }
        
    else {
        answer.push_back(7 - (k + match));
    }
    
    if(match == 1 || match == 0) {
        answer.push_back(6);
    }
    
    else {
        answer.push_back(7 - match);
    }
    
    return answer;
}