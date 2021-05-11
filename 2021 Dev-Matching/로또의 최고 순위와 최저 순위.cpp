#include<string>
#include<vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int rank[7] = {6, 6, 5, 4, 3, 2, 1};
    int min_N = 0;
    
    for(int i = 0; i < win_nums.size(); i++) {
        for(int j = 0; j < lottos.size(); j++) {
            if(lottos.at(j) == win_nums.at(i)) {
                min_N += 1;
            }
        }
    }
    
    int zero = 0;
    
    for(int i = 0; i < lottos.size(); i++) {
        if(lottos.at(i) == 0) {
            zero += 1;
        }
    }
    
    int max_N = min_N + zero;
    
    answer.push_back(rank[max_N]);
    answer.push_back(rank[min_N]);
    
    return answer;
}