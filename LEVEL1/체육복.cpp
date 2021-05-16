#include<string>
#include<vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> arr(n);
    
    for(int i : reserve) {
        arr[i - 1]++;
    }
    
    for(int i : lost) {
        arr[i - 1]--;
    }
    
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] < 0) {
            if(i < (arr.size() - 1) && arr[i + 1] > 0) {
                arr[i]++;
                arr[i + 1]--;
            }
            
            else if(i > 0 && arr[i - 1] > 0) {
                arr[i]++;
                arr[i - 1]++;
            }
        }
    }
    
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] >= 0) {
            answer++;
        }
    }

    return answer;
}