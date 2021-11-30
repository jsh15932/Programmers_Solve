#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;
    
    for(int i = 3; ; i++) {
        if(sum % i == 0) {
            int k = sum / i;
            
            if((i - 2) * (k - 2) == yellow) {
                answer.push_back(k);
                answer.push_back(i);
                
                break;
            }
        }
    }
    
    return answer;
}