#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int arr[7] = {6, 6, 5, 4, 3, 2, 1};
    int min_N = 0;
    
    for(int i = 0; i < win_nums.size(); i++) {
        for(int j = 0; j < lottos.size(); j++) {
            if(lottos.at(j) == win_nums.at(i)) {
                min_N++;
            }
        }
    }
    
    int k = 0;
    
    for(int i = 0; i < lottos.size(); i++) {
        if(lottos.at(i) == 0) {
            k++;
        }
    }
    
    int max_N = min_N + k;
    
    answer.push_back(arr[max_N]);
    answer.push_back(arr[min_N]);
    
    return answer;
}