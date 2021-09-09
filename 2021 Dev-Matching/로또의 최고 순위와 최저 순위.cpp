#include<string>
#include<vector>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int arr[7] = {6, 6, 5, 4, 3, 2, 1};
    int minN = 0;
    
    for(int i = 0; i < win_nums.size(); i++) {
        for(int j = 0; j < lottos.size(); j++) {
            if(lottos[j] == win_nums[i]) {
                minN++;
            }
        }
    }
    
    int k = 0;
    
    for(int i = 0; i < lottos.size(); i++) {
        if(lottos[i] == 0) {
            k++;
        }
    }
    
    int maxN = minN + k;
    
    answer.push_back(arr[maxN]);
    answer.push_back(arr[minN]);
        
    return answer;
}